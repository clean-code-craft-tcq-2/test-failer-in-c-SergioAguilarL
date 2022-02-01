#include <stdio.h>
#include <assert.h>

#define THRESHOLD   200
#define E_OK 200
#define E_NOT_OK 500


int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    
    int retval = 0;
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius <= THRESHOLD){
        
        retval = E_OK;
    }
    else{
        retval = E_NOT_OK;    
    }
    
    return retval;
}

float farenheit2Celcius(float farenheit)
{
    float celcius = 0.0;
    celcius = (farenheit - 32) * 5 / 9;

    return celcius;

}

void alertInCelcius(float farenheit) {
    int celcius;
    celcius = farenheit2Celcius(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != E_OK) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 0);
    alertInCelcius(400.5);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 1);
    alertInCelcius(450.5);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 2);
    printf("All is well (maybe!)\n");
    return 0;
}
