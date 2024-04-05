#include "my.h"

void convert_speed(double speed, t_info *info)
{
	if (speed >= 2000)
		info->speed = 1.0;
	else if (speed >= 1500)
		info->speed = 0.8;
	else if (speed >= 1000)
		info->speed = 0.6;
	else if (speed >= 600)
		info->speed = 0.5;
	else if (speed >= 400)
		info->speed = 0.4;
	else
		info->speed = 0.3;
	run_command_forward(info->speed);
	return;
}

void manage_speed(t_info *info)
{
    double speed;

    if (info->information == NULL || info->information[1] == NULL) {
        return;
	}
	if (!strcmp(info->information[3], "No further info") || !strcmp(info->information[3], "First CP Cleared")) {
		run_command_forward(info->speed);
        return;
	}
    speed = atof(info->information[18]);
    convert_speed(speed, info);
	return;
}

