#pragma once
#include <vector>
#include <iostream>

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
        if (states[currentState] == nullptr)
            return;

        if (states[newState]->CanTransitionFrom(classPointer, currentState) != true)
            return;

        states[currentState]->End(classPointer);

        currentState = newState;

        states[currentState]->Start(classPointer);
    }

    void Update(T* classPointer, float deltaTime)
    {
        if (states[currentState] == nullptr)
            return;

        states[currentState]->Update(classPointer, deltaTime);
    }
};
