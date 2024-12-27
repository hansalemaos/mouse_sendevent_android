# Tuned sendevent with lots of functionality

## Based on [sendevent](https://android.googlesource.com/platform/system/core/+/android-5.0.2_r1/toolbox/sendevent.c)

### Tested against some rooted emulators with [termux breakout](https://github.com/hansalemaos/termuxfree)

## Cmd line args

```sh

Mandatory arguments:
-------------------
	--screen_width
		Necessary to calculate the correct screen coordinates
	--screen_height
		Necessary to calculate the correct screen coordinates
	--device
		The device to use, must support mouse or swipe events.
        Swipe events are not fully supported yet, because there is a good alternative (input swipe)
		Use ls -l /dev/input/ for a complete list

Optional arguments:
------------------
	--x
		The x coodinate destination of the action
	--y
		The y coodinate destination of the action
	--sleep_time
		The time in microseconds to sleep between each mouse action 
	--debug
		Print debug information, can be used as a "faster sleep", if one microsecond sleep time is too slow
	--event_multiply
		Multiplies the number of events, default is 1 which is very, very fast. The higher the number, the slower the movement
	--natural_movement
		Does a logarithmic movement, it starts fast and gets slower when the destination is close.
	--use_every_n_element
		Use every n element, default is 1, makes the movement faster. Good usage is combined with natural_movement
	--start_x
		The x coodinate start of the action (must be positive)
        If not passed, the current mouse position will be used
	--start_y
		The y coodinate start of the action (must be positive)
        If not passed, the current mouse position will be used
	--action
		0 = moves to --x and --y
		1 = moves to --x and --y and then performs a left click
        2 = moves to --x and --y and then performs a right click
		3 = moves to --x and --y and then performs a middle click   
        4 = left click at current mouse position (visible using getevent -lp)
        5 = right click at current mouse position (visible using getevent -lp)
        6 = middle click at current mouse position (visible using getevent -lp) 
        7 = moves to --x and --y and scrolls down at x and y
		8 = scrolls down at current mouse position (visible using getevent -lp)
		9 = moves to --x and --y and scrolls up at x and y
		10 = scrolls up at current mouse position (visible using getevent -lp)
    --min_x_variation; --max_x_variation; --min_y_variation; --max_y_variation
        To make the mouse/swipe movement more natural (not 100% linear)
        These are not real pixels, but calculated in terms of the linux devices values (usually 32767 or 65535)
    --print_device_info
        Print information about all found devices (useful for debugging)
    --click_duration
		Duration of the click in microseconds
    --sleep_time_before_left_click  
        The time in microseconds to sleep before the left click
	--sleep_time_before_right_click
		The time in microseconds to sleep before the right click
	--sleep_time_before_middle_click
		The time in microseconds to sleep before the middle click
    --sleep_time_before_downscroll
		The time in microseconds to sleep before the downscroll
	--sleep_time_before_upscroll
		The time in microseconds to sleep before the upscroll
    --number_of_scrolls
		The number of scrolls
    --sleep_time_between_scrolls
		The time in microseconds to sleep between each scroll

```

```sh

# Install Termux system wide first 

# https://github.com/hansalemaos/termuxfree


# push the file to the device 
adb -s 127.0.0.1:5560 push sendeventmouse.cpp /sdcard

# compile it and run it
cp /sdcard/sendeventmouse.cpp . && g++ -std=c++2a -O3 -g0 sendeventmouse.cpp && ./a.out --screen_width=1920 \
--screen_height=1080 \
--x=800 \
--y=800 \
--sleep_time=0 \
--debug=0 \
--device=/dev/input/event5 \
--event_multiply=2 \
--natural_movement=1 \
--use_every_n_element=30 \
--action=0 \
--print_device_info=1 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--x=100 \
--y=100 \
--sleep_time=0 \
--debug=0 \
--device=/dev/input/event5 \
--event_multiply=2 \
--natural_movement=1 \
--use_every_n_element=10 \
--action=0 \
--print_device_info=0


cp /sdcard/sendeventmouse.cpp . && g++ -std=c++2a -O3 -g0 sendeventmouse.cpp && ./a.out --screen_width=1920 \
--screen_height=1080 \
--x=800 \
--y=800 \
--sleep_time=0 \
--debug=0 \
--device=/dev/input/event5 \
--event_multiply=2 \
--natural_movement=1 \
--use_every_n_element=30 \
--action=0 \
--start_x=700 \
--start_y=700 \
--min_x_variation=0 \
--max_x_variation=300 \
--min_y_variation=0 \
--max_y_variation=300 \
--print_device_info=1 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--x=189 \
--y=268 \
--sleep_time=0 \
--debug=1 \
--device=/dev/input/event5 \
--event_multiply=2 \
--natural_movement=1 \
--use_every_n_element=30 \
--action=1 \
--start_x=100 \
--start_y=100 \
--min_x_variation=0 \
--max_x_variation=300 \
--min_y_variation=0 \
--max_y_variation=300 \
--print_device_info=0 \
--click_duration=1000000 \
--sleep_time_before_left_click=1000000 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--debug=1 \
--device=/dev/input/event5 \
--action=4 \
--click_duration=100000 \
--sleep_time_before_left_click=1000000 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--debug=1 \
--device=/dev/input/event5 \
--action=5 \
--click_duration=100000 \
--sleep_time_before_left_click=1000000 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--debug=1 \
--device=/dev/input/event5 \
--action=6 \
--click_duration=100000 \
--sleep_time_before_left_click=1000000 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--debug=1 \
--device=/dev/input/event5 \
--action=8 \
--number_of_scrolls=8 \
--sleep_time_between_scrolls=10000 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--debug=1 \
--device=/dev/input/event5 \
--action=10 \
--number_of_scrolls=10 \
--sleep_time_between_scrolls=10000
```
