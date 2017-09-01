//
//  speed.c
//
//  Created by Shana Moore on 8/31/17.
//  Copyright © 2017 Shana Moore. All rights reserved.
//

#include <stdio.h>
# define METERS_PER_MILE 1600 // conversion constant
# define SECONDS_PER_HOUR 3600 // conversion constant

int main(void) {
    // Declare variables with appropriate data types
    FILE *fp = NULL;
    
    float distance = 0, hours = 0, meters = 0, seconds = 0,
          miles_per_hour = 0, meters_per_second = 0;
  
    // Assign values
    distance = 425.5f;
    hours = 7.5f;
    
    // Convert the distance to meters
    meters = distance * METERS_PER_MILE;
    
    // Convert the hours to seconds
    seconds = hours * SECONDS_PER_HOUR;
    
    // Output to file + handle error case
    fp = fopen("csis.txt", "w");
    if (NULL == fp) {
        perror("opening csis.txt failed");
        return -1;
    }
    
    // Compute speed
    miles_per_hour = distance / hours;
    meters_per_second = meters / seconds;
    
    // Display speed of car in miles per hour
    printf("The car's speed is %.2f miles/hour.\n", miles_per_hour);
    fprintf(fp, "The car's speed is %.2f miles/hour.\n", miles_per_hour);
    
    
    // Display speed of car in meters per second
    printf("The car's speed is %.2f meters/second.\n", meters_per_second);
    fprintf(fp, "The car's speed is %.2f meters/second.\n", meters_per_second);

    fclose(fp);
    return 0;
}
