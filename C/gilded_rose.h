#ifndef __GILDED_ROSE_H__
#define __GILDED_ROSE_H__

typedef struct
{
    char *name;
    int sell_in;
    int quality;
} Item;

Item* init_item(Item* item, const char *name, int sell_in, int quality);
void update_quality(Item* items, int size);

#endif