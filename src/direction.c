#include "my.h"

void convert_direction(double direction, t_info *info)
{
    fprintf(stderr, "info->information[3]: %s, info->information[34]: %s\n", info->information[3], info->information[34]);
    double sign = atof(info->information[3]) - atof(info->information[34]);
    fprintf(stderr, "direction: %f\n", direction);

    if (direction >= 1500)
		run_command_direction(sign, "0.005\n");
	else if (direction >= 1000)
		run_command_direction(sign, "0.05\n");
	else if (direction >= 600)
		run_command_direction(sign, "0.1\n");
	else if (direction >= 400)
		run_command_direction(sign, "0.2\n");
	else if (direction >= 200)
		run_command_direction(sign, "0.3\n");
	else
		run_command_direction(sign, "0.5\n");
	return;
}

void manage_direction(t_info *info)
{
    double direction;

    if (info->information == NULL || info->information[1] == NULL) {
        return;
    }
    if (!strcmp(info->information[3], "No further info") || !strcmp(info->information[3], "First CP Cleared")) {
        return;
    }
    direction = atof(info->information[17]);
    convert_direction(direction, info);
    return;
}