#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "globals.h"
Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if(modelListener)
	        modelListener->updateBat(vbat);
}
