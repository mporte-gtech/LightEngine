#pragma once
#include <vector>

template<typename T>
class StateBase;

template<typename T>
class StateMachine
{
private:
    std::vector<StateBase<T>*> states;

    int currentState;

public:
    void AddState(StateBase<T>* state)
    {
        states.push_back(state);
    }

    void TryChangeState(T* classPointer, int newState)
    {
        if (states[currentState]->CanTransitionFrom(classPointer, currentState) != true)
            return;

        states[currentState]->End(classPointer);

        currentState = newState;

        states[currentState]->Start(classPointer);
    }

    void Update(T* classPointer, float deltaTime)
    {
        states[currentState]->Update(classPointer, deltaTime);
    }
};
