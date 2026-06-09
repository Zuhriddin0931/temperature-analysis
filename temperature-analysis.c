#include <stdio.h>

// Bir kunning sanasi va haroratini saqlovchi struktura
struct Kun {
    int sana;
    float harorat;
};

// Ma'lumotlarni kiritish
void kirit(struct Kun k[], int n);

// Eng issiq, eng sovuq va o'rtacha haroratni hisoblash
void hisobla(struct Kun k[], int n, int *issiq_index, int *sovuq_index, float *ortacha);

// Natijalarni chiqarish
void chiqar(struct Kun k[], int issiq_index, int sovuq_index, float ortacha);

int main() {
    struct Kun hafta[7];
    int issiq_index, sovuq_index;
    float ortacha;

    // 7 kunlik ma'lumotlarni kiritish
    kirit(hafta, 7);

    // Haroratlar bo'yicha hisob-kitob qilish
    hisobla(hafta, 7, &issiq_index, &sovuq_index, &ortacha);

    // Natijalarni ekranga chiqarish
    chiqar(hafta, issiq_index, sovuq_index, ortacha);

    return 0;
}

void kirit(struct Kun k[], int n) {
    printf("%d kunlik haroratlarni kiriting (sana harorat):\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d %f", &k[i].sana, &k[i].harorat);
    }
}

void hisobla(struct Kun k[], int n, int *issiq_index, int *sovuq_index, float *ortacha) {
    float summa = 0;

    // Dastlab birinchi elementni eng issiq va eng sovuq deb olamiz
    *issiq_index = 0;
    *sovuq_index = 0;

    for (int i = 0; i < n; i++) {
        summa += k[i].harorat;

        // Eng issiq kunni aniqlash
        if (k[i].harorat > k[*issiq_index].harorat)
            *issiq_index = i;

        // Eng sovuq kunni aniqlash
        if (k[i].harorat < k[*sovuq_index].harorat)
            *sovuq_index = i;
    }

    // O'rtacha harorat
    *ortacha = summa / n;
}

void chiqar(struct Kun k[], int issiq_index, int sovuq_index, float ortacha) {
    printf("\nEng issiq kun: %d %.0f\n",
           k[issiq_index].sana,
           k[issiq_index].harorat);

    printf("Eng sovuq kun: %d %.0f\n",
           k[sovuq_index].sana,
           k[sovuq_index].harorat);

    printf("O'rtacha: %.2f\n", ortacha);
}