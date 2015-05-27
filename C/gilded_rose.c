#include <string.h>
#include "gilded_rose.h"

Item*
init_item(Item* item, const char *name, int sell_in, int quality)
{
    item->sell_in = sell_in;
    item->quality = quality;
    item->name = strdup(name);
    
    return item;
}

void update_quality(Item* items, int size) 
{
    int i;
    
    for (i = 0; i < size; i++)
    {
        if (strcmp(items[i].name, "Aged Brie") && strcmp(items[i].name, "Backstage passes to a TAFKAL80ETC concert"))
        {
            if (items[i].quality > 0)
            {
                if (strcmp(items[i].name, "Sulfuras, Hand of Ragnaros"))
                {
                    items[i].quality = items[i].quality - 1;
                }
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality = items[i].quality + 1;

                if (!strcmp(items[i].name, "Backstage passes to a TAFKAL80ETC concert"))
                {
                    if (items[i].sell_in < 11)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }

                    if (items[i].sell_in < 6)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }
                }
            }
        }

        if (strcmp(items[i].name, "Sulfuras, Hand of Ragnaros"))
        {
            items[i].sell_in = items[i].sell_in - 1;
        }

        if (items[i].sell_in < 0)
        {
            if (strcmp(items[i].name, "Aged Brie"))
            {
                if (strcmp(items[i].name, "Backstage passes to a TAFKAL80ETC concert"))
                {
                    if (items[i].quality > 0)
                    {
                        if (strcmp(items[i].name, "Sulfuras, Hand of Ragnaros"))
                        {
                            items[i].quality = items[i].quality - 1;
                        }
                    }
                }
                else
                {
                    items[i].quality = items[i].quality - items[i].quality;
                }
            }
            else
            {
                if (items[i].quality < 50)
                {
                    items[i].quality = items[i].quality + 1;
                }
            }
        }
    }
}
