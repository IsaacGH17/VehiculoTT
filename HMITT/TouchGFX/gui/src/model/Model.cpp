#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "globals.h"
Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if(modelListener)
	{
		modelListener->updateBat(vbat);
		modelListener->updatePWM(pwm);
		modelListener->updateDist(dist_mm);
	}

}
