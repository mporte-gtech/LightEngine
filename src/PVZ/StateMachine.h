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

    void TryChangeState(T* selfPointer, int newState)
    {
        if (states[currentState]->CanTransitionFrom(selfPointer, currentState) != true)
            return;

        states[currentState]->End(selfPointer);

        currentState = newState;

        states[currentState]->Start(selfPointer);
    }

    void Update(T* selfPointer, float deltaTime)
    {
        states[currentState]->Update(selfPointer, deltaTime);
    }
};
