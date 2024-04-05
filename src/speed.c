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
    fprintf(stderr, "speed converted: %f\n", info->speed);
	run_command_forward(info->speed);
	return;
}

void manage_speed(char ** data, t_info *info)
{
    double speed;

    if (data == NULL || data[1] == NULL) {
        return;
	}
	if (!strcmp(data[3], "No further info") || !strcmp(data[3], "First CP Cleared")) {
		fprintf(stderr, "No further info: %s\n", data[3]);
		run_command_forward(info->speed);
        return;
	}
    speed = atof(data[15]);
    fprintf(stderr, "speed: %f\n", speed);
    convert_speed(speed, info);
	return;
}

