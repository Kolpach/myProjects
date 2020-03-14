#pragma once
#include "includeLibs.h"
class ICommand
{
public:
	virtual ~ICommand() = default;
	virtual void execute() = 0;
};