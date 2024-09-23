#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
    if (index >= 0 && index < 5)
    {
        item_list[index].name = (char*)malloc(sizeof(char)*strlen(name));
        item_list[index].sku = (char*)malloc(sizeof(char)*strlen(sku));
        item_list[index].category = (char*)malloc(sizeof(char)*strlen(category));

        item_list[index].price = price;
        strcpy(item_list[index].name,name);
        strcpy(item_list[index].sku,sku);
        strcpy(item_list[index].category,category);
    }
}

void free_items(Item *item_list, int size)
{
    for (int i = 0; i < size; i++)
    {
    free(item_list[i].name);
    free(item_list[i].sku);
    free(item_list[i].category);
    }
    free(item_list);
}

double average_price(Item *item_list, int size)
{
    double sum = 0, avg = 0;
    for(int i = 0; i < size; i++)
    {
        sum += item_list[i].price;
    }
    avg = sum/size;
    printf("The average price is $%f.\n",avg);
    return avg;
}

void print_items(Item *item_list, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Name: %s\nSku: %s\nPrice: %f\nCategory: %s\n\n",item_list[i].name, item_list[i].sku, item_list[i].price, item_list[i].category);
    }
}

void item_find(Item *item_list, char sku, int size)
{

    while (/* condition */)
    {
        /* code */
    }
    



}

int main(int argc, char*argv[])
{

    int num_item = 5;
    int index;
    Item *item_list = (Item*)malloc(sizeof(Item)*num_item);

    add_item(item_list, 1.99, "1", "drink", "soda", index);
    index++; 
    
    add_item(item_list, 0.99, "2", "snack", "candy", index);
    index++;

    add_item(item_list, 1.99, "3", "snack", "gum", index);
    index ++;

    add_item(item_list, 1.99, "4", "snack", "chip", index);
    index++;

    add_item(item_list, 1.99, "5", "dessert", "ice cream", index);
    index++;

    char sku_search;
    sku_search = argv[1];


    print_items(item_list, num_item);
    average_price(item_list, num_item);
    free_items(item_list, num_item);

    return 0;
}