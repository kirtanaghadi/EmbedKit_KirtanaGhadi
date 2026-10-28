
#include <stdio.h>
#include <stdint.h>

#define SIZE 8

uint8_t buffer[SIZE];
int head = 0, tail = 0, count = 0;

int write_data(uint8_t data)
{
    if (count == SIZE)
        return 0;

    buffer[head] = data;
    head = (head + 1) & (SIZE - 1);
    count++;

    return 1;
}

int read_data(uint8_t *data)
{
    if (count == 0)
        return 0;

    *data = buffer[tail];
    tail = (tail + 1) & (SIZE - 1);
    count--;

    return 1;
}

int main(void)
{
    uint8_t data;
    int i;

    for (i = 0; i < SIZE; i++)
    {
        data = 0x41 + i;

        if (write_data(data))
            printf("[WRITE] 0x%02X -> OK (count=%d)%s\n",
                   data, count, count == SIZE ? " FULL" : "");
    }

    if (!write_data(0x99))
        printf("[WRITE] 0x99 -> FAIL (buffer full)\n");

    for (i = 0; i < 3; i++)
    {
        read_data(&data);
        printf("[READ] -> 0x%02X (count=%d)\n", data, count);
    }

    for (i = 0; i < 3; i++)
    {
        data = 0x49 + i;

        if (write_data(data))
            printf("[WRITE] 0x%02X -> OK (count=%d)%s\n",
                   data, count, count == SIZE ? " FULL" : "");
    }

    while (read_data(&data))
        printf("[READ] -> 0x%02X (count=%d)\n", data, count);

    if (!read_data(&data))
        printf("[READ] (empty) -> FAIL (buffer empty)\n");

    return 0;
}
