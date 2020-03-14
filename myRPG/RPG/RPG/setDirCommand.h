#pragma once
#include "ICommand.h"
#include "Entity.h"
class setDirCommand : public ICommand {
	Entity* object;
	float x, y;
public:
	setDirCommand(Entity* object, float x, float y);
	virtual ~setDirCommand() = default;
	virtual void execute() override;
};