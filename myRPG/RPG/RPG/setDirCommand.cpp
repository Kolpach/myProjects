#include "setDirCommand.h"


setDirCommand::setDirCommand(Entity*  obj, float lx, float ly) : object(obj), x(lx), y(ly) { }

void setDirCommand::execute() {
	object->addDirrection(x, y);
}