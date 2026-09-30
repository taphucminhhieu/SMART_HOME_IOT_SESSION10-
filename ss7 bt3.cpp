#include <stdio.h>
#include <math.h>

struct UnoptimizedDevice {
    int status;
    float voltage;
    int id;
    float current;
    char name[20];
    float powerSensor;
    float timeMinutes;
};

struct OptimizedDevice {
    char name[20];
    float voltage;
    float current;
    float powerSensor;
    float timeMinutes;
    int id;
    int status;
};

int main() {
    printf("Size unoptimized: %lu bytes\n", sizeof(struct UnoptimizedDevice));
    printf("Size optimized: %lu bytes\n", sizeof(struct OptimizedDevice));

    int id, status;
    char name[20];
    float voltage, current, powerSensor, timeMinutes;

    printf("Nhap ID: ");
    scanf("%d", &id);
    printf("Nhap ten thiet bi: ");
    scanf("%19s", name);
    printf("Nhap trang thai (0 hoac 1): ");
    scanf("%d", &status);
    printf("Nhap dien ap (V): ");
    scanf("%f", &voltage);
    printf("Nhap dong dien (A): ");
    scanf("%f", &current);
    printf("Nhap cong suat cam bien (W): ");
    scanf("%f", &powerSensor);
    printf("Nhap thoi gian hoat dong (phut): ");
    scanf("%f", &timeMinutes);

    if (voltage <= 0 || current < 0 || timeMinutes < 0 || (status != 0 && status != 1)) {
        printf("Loi: Du lieu dau vao khong hop le!\n");
        return 0;
    }

    float pCalc = voltage * current;

    if (fabs(powerSensor - pCalc) > 0.05f * pCalc && pCalc > 0) {
        printf("Canh bao: Cam bien cong suat bao sai lech!\n");
    }

    if (current > 30.0f || powerSensor > 6600.0f) {
        printf("Canh bao: QUA TAI NGUY HIEM!\n");
    }

    if (status == 0 && current > 0.05f) {
        printf("Canh bao: RO RI DIEN HOAC TAI AN!\n");
    }

    float kWh = (powerSensor * (timeMinutes / 60.0f)) / 1000.0f;
    printf("Dien nang tieu thu: %.4f kWh\n", kWh);

    return 0;
}
