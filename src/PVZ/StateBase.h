#pragma once

template<typename T>
class StateBase
{
public:
	virtual void Start(T* classPointer) = 0;

	virtual void Update(T* classPointer, float deltaTime) = 0;

	virtual void End(T* classPointer) = 0;

	virtual bool CanTransitionFrom(T* classPointer, int currentState) = 0;
};
