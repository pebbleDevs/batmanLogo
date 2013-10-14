#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"
//#include "myPebbleFunctions.h"


#define MY_UUID { 0x73, 0xC6, 0x01, 0xC7, 0x71, 0x7D, 0x44, 0x31, 0x9F, 0x0B, 0x15, 0x27, 0x47, 0xF9, 0x66, 0x01 }
PBL_APP_INFO(MY_UUID,
             "Batman Logo", "mApps Lab",
             1, 0, /* App version */
             RESOURCE_ID_IMAGE_MENU_ICON,
             APP_INFO_WATCH_FACE);

Window window;
//Bitmap area for logo
BmpContainer background_image;
Layer background_layer;

TextLayer text_time_layer;
TextLayer text_ampm_layer;
TextLayer text_date_layer;
TextLayer text_month_layer;
TextLayer text_day_layer;
TextLayer text_string_layer;

GFont batman_letters_15, batman_letters_20, batman_numbers_40;

TextLayer text_creditLine1_layer;
TextLayer text_creditLine2_layer;
TextLayer text_versionInfo_layer;

void creditBanner()
{
 //initilizing the creditline layer
  text_layer_init(&text_creditLine1_layer, window.layer.frame);
  //setting the layer attributes
  text_layer_set_text_color(&text_creditLine1_layer, GColorBlack);
  text_layer_set_background_color(&text_creditLine1_layer, GColorClear);
  //positioning attributes
  text_layer_set_text_alignment(&text_creditLine1_layer, GTextAlignmentCenter);
  layer_set_frame(&text_creditLine1_layer.layer, GRect(-8,80,164,20));
  //Font attribute
  batman_letters_15 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BATMAN_FOREVER_LETTERS_15));
  text_layer_set_font(&text_creditLine1_layer, batman_letters_15);
  layer_add_child(&window.layer, &text_creditLine1_layer.layer);
  text_layer_set_text(&text_creditLine1_layer,"Developed By");
  
  //initilizing the layer  
  text_layer_init(&text_creditLine2_layer, window.layer.frame);
  //setting the layer attributes 
  text_layer_set_text_color(&text_creditLine2_layer, GColorBlack);
  text_layer_set_background_color(&text_creditLine2_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_creditLine2_layer, GTextAlignmentCenter);
  layer_set_frame(&text_creditLine2_layer.layer, GRect(-8,100,160,20));
  //Font attribute
  batman_letters_20 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BATMAN_FOREVER_LETTERS_20));
  text_layer_set_font(&text_creditLine2_layer, batman_letters_20);
  layer_add_child(&window.layer, &text_creditLine2_layer.layer);
  text_layer_set_text(&text_creditLine2_layer,"alokc83");
  
      //initilizing the text_versionInfo_layer  
  text_layer_init(&text_versionInfo_layer, window.layer.frame);
  //setting the layer attributes 
  text_layer_set_text_color(&text_versionInfo_layer, GColorBlack);
  text_layer_set_background_color(&text_versionInfo_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_versionInfo_layer, GTextAlignmentCenter);
  layer_set_frame(&text_versionInfo_layer.layer, GRect(0,120,120,40));
  //Font attribute
  text_layer_set_font(&text_versionInfo_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  layer_add_child(&window.layer, &text_versionInfo_layer.layer);
  text_layer_set_text(&text_versionInfo_layer, "Version 1.2");
  
}


void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Batman Logo");
  window_stack_push(&window, true /* Animated */);
  window_set_background_color(&window, GColorWhite);
  
  //Resource Map initialization
  resource_init_current_app(&APP_RESOURCES);
  
  // gfx layer init 
  layer_init(&background_layer, window.layer.frame);
  bmp_init_container(RESOURCE_ID_BATMAN_LOGO_BOW, &background_image);
  layer_set_frame(&background_image.layer.layer, GRect(0,5,140,50));
  layer_add_child(&window.layer, &background_image.layer.layer);


//font initilization for all layers
  batman_letters_20 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BATMAN_FOREVER_LETTERS_20));



 
  //initilizing the text time layer
  text_layer_init(&text_time_layer, window.layer.frame);
  text_layer_set_text_color(&text_time_layer, GColorBlack);
  text_layer_set_background_color(&text_time_layer, GColorClear);
  //positioning attributes
  text_layer_set_text_alignment(&text_time_layer, GTextAlignmentCenter);
  layer_set_frame(&text_time_layer.layer, GRect(-8,70,160,40));
  //Font atterbutes
  batman_numbers_40 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BATMAN_FOREVER_NUMBERS_SUBSET_40));
  text_layer_set_font(&text_time_layer, batman_numbers_40);
  layer_add_child(&window.layer, &text_time_layer.layer);
  
  
  //initilizing the AM_PM layer  
  text_layer_init(&text_ampm_layer, GRect(92,55,50,20));
  //setting the layer attributes 
  text_layer_set_text_color(&text_ampm_layer, GColorBlack);
  text_layer_set_background_color(&text_ampm_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_ampm_layer, GTextAlignmentRight);  
  //Font attribute
  text_layer_set_font(&text_ampm_layer, batman_letters_20);
  layer_add_child(&window.layer, &text_ampm_layer.layer); 

  //initilizing the day of week layer  
  //text_layer_init(&text_day_layer, window.layer.frame);
 //layer_set_frame(&text_day_layer.layer, GRect(10,143,30,148));
  text_layer_init(&text_day_layer, GRect(3,110,80,20));
  //setting the layer attributes 
  text_layer_set_text_color(&text_day_layer, GColorBlack);
  text_layer_set_background_color(&text_day_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_day_layer, GTextAlignmentLeft);
  //Font attribute
  text_layer_set_font(&text_day_layer, batman_letters_20);
  layer_add_child(&window.layer, &text_day_layer.layer);
  
  //initilizing the Month layer  
  //text_layer_init(&text_month_layer, window.layer.frame);
 //layer_set_frame(&text_month_layer.layer, GRect(10,143,30,148));
  text_layer_init(&text_month_layer, GRect(62,110,80,20));
  //setting the layer attributes 
  text_layer_set_text_color(&text_month_layer, GColorBlack);
  text_layer_set_background_color(&text_month_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_month_layer, GTextAlignmentRight);
  //Font attribute
  text_layer_set_font(&text_month_layer, batman_letters_20);
  layer_add_child(&window.layer, &text_month_layer.layer);
  
  
  //initilizing the date layer  
  //text_layer_init(&text_date_layer, window.layer.frame);
  //layer_set_frame(&text_date_layer.layer, GRect(60,143,65,148));
  //instead of above two line line below can be used.
  text_layer_init(&text_date_layer, GRect(40,122,70,40));
  //setting the layer attributes 
  text_layer_set_text_color(&text_date_layer, GColorBlack);
  text_layer_set_background_color(&text_date_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_date_layer, GTextAlignmentCenter);  
  //Font attribute
  text_layer_set_font(&text_date_layer, batman_numbers_40);
  layer_add_child(&window.layer, &text_date_layer.layer);
  
  creditBanner();
/*  
  // date of month label
  text_layer_init(&text_date_layer, window.layer.frame);
  text_layer_set_background_color(&text_date_layer, GColorClear);
  text_layer_set_text_color(&text_date_layer, GColorBlack);
  layer_set_frame(&text_date_layer.layer, GRect(0, 0, 144-8, 168-68));
  text_layer_set_font(&text_date_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BATMAN_FOREVER_SUBSET_30)));
  layer_add_child(&window.layer, &text_date_layer.layer);
  
  // string
  text_layer_init(&text_date_layer, window.layer.frame);
  text_layer_set_background_color(&text_string_layer, GColorClear);
  text_layer_set_text_color(&text_string_layer, GColorBlack);
  layer_set_frame(&text_string_layer.layer, GRect(0, 0, 100, 100));
  text_layer_set_font(&text_string_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BATMAN_FOREVER_SUBSET_30)));
  layer_add_child(&window.layer, &text_string_layer.layer);
*/
  
  PblTm tick_time;
  get_time(&tick_time);
}

void handle_minute_tick(AppContextRef ctx, PebbleTickEvent *t) {

  (void)ctx;
  
  static char time_text[] = "00:00";
  static char ampm_text[] = "XX";
  static char day_text[] = "XXXXX";
  static char new_day_text[] = "NNN";
  static char month_text[] = "XXX";
  static char new_month_text[] = "NNN";
  static char date_text[] = "XX";
  static char new_date_text[] = "NN";
  
  char *time_format; // TODO for 12 or 24 hrs suuport
  PblTm current_time;
  get_time(&current_time); 
 
 // Hiding the credit line layers
 psleep(1000);
 layer_set_hidden((Layer *)&text_creditLine1_layer, true);
 layer_set_hidden((Layer *)&text_creditLine2_layer, true);
 layer_set_hidden((Layer *)&text_versionInfo_layer, true);
 
 // 24 or 12 hrs format
 if (clock_is_24h_style()) {
    time_format = "%R";
  } else {
    time_format = "%I:%M";
    //setting am or pm 
    string_format_time(ampm_text,sizeof(ampm_text), "%p", &current_time);
    text_layer_set_text(&text_ampm_layer, ampm_text);
    //text_layer_set_text(&text_ampm_layer, "MM");
  }
 
  string_format_time(time_text, sizeof(time_text), time_format, &current_time);
/* if (!clock_is_24h_style() && (time_text[0] == '0')) 
 {
             memmove(time_text, &time_text[1], sizeof(time_text) - 1);
 } */

text_layer_set_text(&text_time_layer, time_text);

// Populating the day layer
//Not pupulating unless day is different
  string_format_time(new_day_text,sizeof(day_text), "%a", &current_time);
  if(strncmp(new_day_text, day_text, sizeof(day_text)) != 0)
  	{
  		strncpy(day_text, new_day_text, sizeof(day_text));
  		text_layer_set_text(&text_day_layer, day_text);
  	}

//populating month layer %b=Jun, %B = June
 string_format_time(new_month_text, sizeof(month_text), "%b", &current_time);
 if(strncmp(new_month_text, month_text, sizeof(month_text)) != 0)
 	{
     	strncpy(month_text, new_month_text, sizeof(month_text));
     	text_layer_set_text(&text_month_layer, month_text);  	
  	 }
  	 
//populating date field 
//Not pupulating unless date is different
  string_format_time(new_date_text,sizeof(date_text), "%d", &current_time);
  if(strncmp(new_date_text, date_text, sizeof(date_text)) != 0)
  	{
  		strncpy(date_text, new_date_text, sizeof(date_text));
  		text_layer_set_text(&text_date_layer, date_text);
  	}
  	 

}

//dealloccation when watchface is close
void handle_deinit(AppContextRef ctx) {
        (void)ctx;
      vibes_short_pulse();
      bmp_deinit_container(&background_image);
      fonts_unload_custom_font(batman_letters_20);
      fonts_unload_custom_font(batman_numbers_40);
     
}


/*
void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
} */ // main created by project creator

void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init,

    .tick_info = {
      .tick_handler = &handle_minute_tick,
      .tick_units = MINUTE_UNIT
    }

  };
  app_event_loop(params, &handlers);
}
