#include <stdio.h>
#include <iostream>
#include <string.h>
#include <alsa/asoundlib.h>

int main()
{
 
 std::cout << "HELLO ALSA." << std::endl;
 
 register int err;
 int cardNum = -1;
 
 for (;;) 
 {
 
   snd_ctl_t * cardHandle;
   
   if (( err = snd_card_next(&cardNum))< 0) {
    break;
   }
   
   if ( cardNum < 0 ) break;
   
   {
   char str[26];
   sprintf( str, "hw:%i", cardNum);
   if (( err = snd_ctl_open( &cardHandle, str, 0)) < 0 ) {
    printf("Can not open card %i: %s\n", cardNum, snd_strerror(err));
   }
   }
   
   {
   snd_ctl_card_info_t *cardInfo;
   snd_ctl_card_info_alloca(&cardInfo);
   
   if (( err = snd_ctl_card_info( cardHandle, cardInfo)) < 0 ){
   	 printf("Cant get info for card %i: %s\n",cardNum,snd_strerror(err));
   }else{
   	 printf("Card %i = %s \n", cardNum, snd_ctl_card_info_get_name(cardInfo));
   }
   
   int devNum = -1;
   int totalDevices = 0;
   
   for( ;; ) 
   {
   	if(( err = snd_ctl_pcm_next_device( cardHandle, &devNum)) < 0)
   	{
   		break;
   	}
   	
   	if( devNum < 0 ) break;
   	
   	++totalDevices;
   }
  	
   printf( "Found %i digital audio device on card %i\n", totalDevices,cardNum);	 
   }
   snd_ctl_close(cardHandle);
 }
 
 snd_config_update_free_global();
 return 0;
}
