#pragma once
#include "includeLibs"
class ICommand
{
public:
	sf
	virtual ~ICommand() = default;
	virtual void execute() = 0;
};

