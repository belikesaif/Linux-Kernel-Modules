#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

struct birthday
{
int month;
int day;
int year;
char *name;
struct list_head list;
};

/**
* The following defines and initializes a list_head object named birthday_list
*/
static LIST_HEAD(birthday_list);
struct birthday *person;
struct birthday *next;


int simple_init(void)
{
printk(KERN_INFO "**Loading Module**\n");

person = kmalloc(sizeof(*person), GFP_KERNEL);
person->name = "Saif";
person->day = 29;
person->month = 7;
person->year = 2001;
INIT_LIST_HEAD(&person->list);
list_add_tail(&person->list, &birthday_list);
  
person = kmalloc(sizeof(*person), GFP_KERNEL);
person->name = "Roshail";
person->day = 11;
person->month = 8;
person->year = 2000;
INIT_LIST_HEAD(&person->list);
list_add_tail(&person->list, &birthday_list);
  
person = kmalloc(sizeof(*person), GFP_KERNEL);
person->name = "Zoha";
person->day = 18;
person->month = 12;
person->year = 1998;
INIT_LIST_HEAD(&person->list);
list_add_tail(&person->list, &birthday_list);
  
person = kmalloc(sizeof(*person), GFP_KERNEL);
person->name = "Kashan Sunny Mazhar";
person->day = 13;
person->month = 4;
person->year = 2000;
INIT_LIST_HEAD(&person->list);
list_add_tail(&person->list, &birthday_list);
  
  
person = kmalloc(sizeof(*person), GFP_KERNEL);
person->name = "Sufyan";
person->day = 23;
person->month = 1;
person->year = 1999;
INIT_LIST_HEAD(&person->list);
list_add_tail(&person->list, &birthday_list);

person = kmalloc(sizeof(*person), GFP_KERNEL);
person->name = "Hamza";
person->day = 23;
person->month = 1;
person->year = 2001;
INIT_LIST_HEAD(&person->list);
list_add_tail(&person->list, &birthday_list);

list_for_each_entry(person, &birthday_list, list) {
printk(KERN_INFO "Name: %s Birthday: Month: %d Day: %d Year: %d", person->name, person->month, person->day, person->year);
}
  
return 0;
}

void simple_exit(void)
{
printk(KERN_INFO "**Removing Module**\n");
list_for_each_entry_safe(person,next,&birthday_list,list) {
printk(KERN_INFO "Removing %s %d %d %d", person->name, person->month, person->day, person->year);
list_del(&person->list);
kfree(person);
}
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");