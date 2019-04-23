#include <linux/slab.h>
#include <linux/time.h>
#include <asm/string.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>
#define NSEC_PER_MSEC   1000000L
#define TIMEINTERVAL	60000
			//60 seconds (60,000 ms)

MODULE_LICENSE("GPL"); //Don't want to taint the kernel!
MODULE_AUTHOR("Team CAPA");
MODULE_DESCRIPTION("Network IDS Hub");
MODULE_VERSION("0.1");

static char* scriptDir = "/bin/capaguard/" //Location of the scripts.
static char* execEnvironment = "/bin/bash" //What shell we will be using.


static struct hrtimer hr_timer;

enum hrtimer_restart enHRTimer=HRTIMER_NORESTART;
s64 i64TimeInNsec = TIMEINTERVAL * NSEC_PER_MSEC;

/* timer_callback()
 * This function gets called every time the timer expires
 */
enum hrtimer_restart timer_callback( struct hrtimer *timer )
{
    hrtimer_forward(timer,hrtimer_cb_get_time(timer),ktime_set(0,i64TimeInNsec));
    printk(KERN_INFO "[CAPA] Timer callback function triggered...");   
    //Here we would likely call the script that has snort look through our log files.

    //char* argv[] = {execEnvironment, scriptDir+"exampleScript.sh", NULL};
    // /* This command should call our arguments we specified above." */
    //call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC); 
    return enHRTimer;
}

/* kinit_func
 * This function gets called when the kernel is inserted. As such it is only run once.
 */
static int __init kinit_func(void) {

    ktime_t kt;

    enHRTimer = HRTIMER_RESTART;

    //HRT init  
    kt = ktime_set(0, i64TimeInNsec);
    hrtimer_init( &hr_timer, CLOCK_REALTIME, HRTIMER_MODE_ABS);
    hrtimer_set_expires(&hr_timer, kt);
    hr_timer.function = &timer_callback;
    hrtimer_start( &hr_timer, kt, HRTIMER_MODE_ABS);


 printk(KERN_INFO "[CAPA] CAPA Guard initialized.");
 return 0;
}

/* kexit_func
 * This function gets called when the module is removed.
 */
static void __exit kexit_func(void) {
 hrtimer_cancel(&hr_timer);
 enHRTimer = HRTIMER_NORESTART;
 printk(KERN_INFO "[CAPA] CAPA Guard terminating...");
}

module_init(kinit_func);
module_exit(kexit_func);
