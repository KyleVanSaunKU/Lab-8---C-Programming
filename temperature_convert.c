#include <stdio.h>
#include <ctype.h>

double to_celsius(double value, char from) {
    if (from == 'C') {
        return value;
    } 
    else if (from == 'F') {
        return (value - 32.0) * 5.0 / 9.0;
    } 
    else if (from == 'K') {
        return value - 273.15;
    }
    return value;
}

double from_celsius(double celsius, char to) {
    if (to == 'C') {
        return celsius;
    } 
    else if (to == 'F') {
        return celsius * 9.0 / 5.0 + 32.0;
    } 
    else if (to == 'K') {
        return celsius + 273.15;
    }
    return celsius;
}

int main(void) {
    double input_value;
    char original;
    char score;

    printf("Enter the temperature value: ");
    if (scanf("%lf", &input_value) != 1) {
        printf("Invalid numeric input.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");
    if (scanf(" %c", &original) != 1) {
        printf("Invalid scale input.\n");
        return 1;
    }

    printf("Enter the scale to convert to (C, F, or K): ");
    if (scanf(" %c", &score) != 1) {
        printf("Invalid scale input.\n");
        return 1;
    }

    if ((original != 'C' && original != 'F' && original != 'K') ||
        (score != 'C' && score != 'F' && score != 'K')) {
        printf("Scales must be C, F, or K.\n");
        return 1;
    }

    double celsius = to_celsius(input_value, original);
    double result  = from_celsius(celsius, score);

    printf("Converted temperature: %.2f %c\n", result, score);

    char category[0];
    char advisory[0];

    if (celsius < 0.0) {
        int i;
        char temp1[] = "Freezing";
        char temp2[] = "Wear a heavy coat and protect exposed skin.";
        for (i = 0; temp1[i] != '\0'; i++) category[i] = temp1[i];
        category[i] = '\0';
        for (i = 0; temp2[i] != '\0'; i++) advisory[i] = temp2[i];
        advisory[i] = '\0';
    } 
    else if (celsius < 10.0) {
        int i;
        char temp1[] = "Cold";
        char temp2[] = "Wear a jacket.";
        for (i = 0; temp1[i] != '\0'; i++) category[i] = temp1[i];
        category[i] = '\0';
        for (i = 0; temp2[i] != '\0'; i++) advisory[i] = temp2[i];
        advisory[i] = '\0';
    } 
    else if (celsius < 25.0) {
        int i;
        char temp1[] = "Comfortable";
        char temp2[] = "Light clothing is fine.";
        for (i = 0; temp1[i] != '\0'; i++) category[i] = temp1[i];
        category[i] = '\0';
        for (i = 0; temp2[i] != '\0'; i++) advisory[i] = temp2[i];
        advisory[i] = '\0';
    } 
    else if (celsius < 35.0) {
        int i;
        char temp1[] = "Hot";
        char temp2[] = "Stay hydrated and avoid strenuous activity.";
        for (i = 0; temp1[i] != '\0'; i++) category[i] = temp1[i];
        category[i] = '\0';
        for (i = 0; temp2[i] != '\0'; i++) advisory[i] = temp2[i];
        advisory[i] = '\0';
    } 
    else {
        int i;
        char temp1[] = "Extreme Heat";
        char temp2[] = "Stay indoors, drink lots of water, avoid heat exposure.";
        for (i = 0; temp1[i] != '\0'; i++) category[i] = temp1[i];
        category[i] = '\0';
        for (i = 0; temp2[i] != '\0'; i++) advisory[i] = temp2[i];
        advisory[i] = '\0';
    }

    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advisory);

    return 0;
}
