/*
 * fsm_manual.c
 *
 *  Created on: Oct 19, 2023
 *      Author: Admin
 */

#include"fsm_manual.h"
#include"fsm_automatic.h"

void fsm_manual_run(){
	switch(status){
		case MAN_INIT:
			clear();
			clear_follow();
			set_7segled_mode(1);
			if(isButton1Pressed()==1){
				MAN_duration =0;
				status = MAN_RED;
				set_Timer1(500);
			}
			if(timer1_flag == 1){
				status = AUTO_RED;
				reset_counter();				//for counting down time
				set_Timer1(red_duration*100);
			}
			break;
		case MAN_RED:
//			set_red();
//			set_red_follow();
			set_7segled_mode(2);
			set_7segled_duration(MAN_duration);
			if(timer1_flag == 1){
				status = AUTO_RED;
				reset_counter();				//for counting down time
				set_Timer1(red_duration*100);
			}
			if(isButton1Pressed()==1){
				MAN_duration =0;
				status = MAN_GREEN;
				set_Timer1(500);
			}
			// when press button2 update red duaration
			if(isButton2Pressed()==1){
				set_autoAjust_red(MAN_duration);
				//red_duration = MAN_duration;
				set_Timer1(200);
				if(timer1_flag==1){
					status = AUTO_RED;
					reset_counter();				//for counting down time
					MAN_duration=0;
				}

			}

			break;
	////////////////////////////////////////
		case MAN_GREEN:
//			set_green();
//			set_green_follow();
			set_7segled_mode(3);
			set_7segled_duration(MAN_duration);
			if(timer1_flag==1){
				status = AUTO_RED;
				reset_counter();				//for counting down time
				set_Timer1(green_duration*100);
			}
			if(isButton1Pressed()==1){
				MAN_duration =0;
				status = MAN_YELLOW;
				set_Timer1(500);
			}
			// when press button2 update green duration
			if(isButton2Pressed()==1){
				set_autoAjust_green(MAN_duration);
				//green_duration = MAN_duration;
				set_Timer1(200);
				if(timer1_flag==1){
					status = AUTO_RED;				//Back to red and do auto
					reset_counter();				//for counting down time
					MAN_duration=0;
				}
			}


			break;
	///////////////////////////////////////////////////
		case MAN_YELLOW:
//			set_yellow();
//			set_yellow_follow();
			set_7segled_mode(4);
			set_7segled_duration(MAN_duration);
			if(timer1_flag==1){
				status = AUTO_RED;
				reset_counter();				//for counting down time
				set_Timer1(yellow_duration*100);
			}
			if(isButton1Pressed()==1){
				MAN_duration =0;
				status = MAN_INIT;
				set_Timer1(500);
			}
			if(isButton2Pressed()==1){
				set_autoAjust_yellow(MAN_duration);
				//yellow_duration = MAN_duration;
				set_Timer1(200);
				if(timer1_flag==1){
					status = AUTO_RED;				//Back to red and do auto
					reset_counter();				//for counting down time
					MAN_duration=0;
				}
			}

			break;
		default:
			break;

	}
}

