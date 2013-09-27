#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"
//#include "myPebbleFunctions.h"


#define MY_UUID { 0x73, 0xC6, 0x01, 0xC7, 0x71, 0x7D, 0x44, 0x31, 0x9F, 0x0B, 0x15, 0x27, 0x47, 0xF9, 0x66, 0x01 }
PBL_APP_INFO(MY_UUID,
             "Batman Logo", "mApps Lab",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_WATCH_FACE);

Window window;
//Bitmap area for logo
BmpContainer background_image;
Layer background_layer;

TextLayer text_time_layer;
TextLayer text_date_layer;
TextLayer text_string_layer;

GFont batman_letters_15, batman_letters_20, batman_numbers_40;

TextLayer text_creditLine1_layer;
TextLayer text_creditLine2_layer;

void creditBanner()
{
 //initilizing the creditline layer
  text_layer_init(&text_creditLine1_layer, window.layer.frame);
  //setting the layer attributes
  text_layer_set_text_color(&text_creditLine1_layer, GColorBlack);
  text_layer_set_background_color(&text_creditLine1_layer, GColorClear);
  //positioning attributes
  text_layer_set_text_alignment(&text_creditLine1_layer, GTextAlignmentCenter);
  layer_set_frame(&text_creditLine1_layer.layer, GRect(15,80,150,90));
  //Font attribute
  batman_letters_15 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BATMAN_FOREVER_LETTERS_15));
  text_layer_set_font(&text_creditLine1_layer, batman_letters_15);
  layer_add_child(&window.layer, &text_creditLine1_layer.layer);
  text_layer_set_text(&text_creditLine1_layer,"Created By");
  
  //initilizing the layer  
  text_layer_init(&text_creditLine2_layer, window.layer.frame);
  //setting the layer attributes 
  text_layer_set_text_color(&text_creditLine2_layer, GColorBlack);
  text_layer_set_background_color(&text_creditLine2_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_creditLine2_layer, GTextAlignmentCenter);
  layer_set_frame(&text_creditLine2_layer.layer, GRect(20,100,160,120));
  //Font attribute
  batman_letters_20 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BATMAN_FOREVER_LETTERS_20));
  text_layer_set_font(&text_creditLine2_layer, batman_letters_20);
  layer_add_child(&window.layer, &text_creditLine2_layer.layer);
  text_layer_set_text(&text_creditLine2_layer,"alokc83");
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
  layer_set_frame(&background_image.layer.layer, GRect(0,10,140,50));
  layer_add_child(&window.layer, &background_image.layer.layer);

 
  //initilizing the text time layer
  text_layer_init(&text_time_layer, window.layer.frame);
  text_layer_set_text_color(&text_time_layer, GColorBlack);
  text_layer_set_background_color(&text_time_layer, GColorClear);
  
  //positioning attributes
  text_layer_set_text_alignment(&text_time_layer, GTextAlignmentCenter);
  layer_set_frame(&text_time_layer.layer, GRect(0,80,160,120));
  //Font atterbutes
  batman_numbers_40 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BATMAN_FOREVER_NUMBERS_SUBSET_40));
  text_layer_set_font(&text_time_layer, batman_numbers_40);
  layer_add_child(&window.layer, &text_time_layer.layer);
  
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
  char *time_format="%R"; // TODO for 12 or 24 hrs suuport
 
 // Hiding the credit line layers
 psleep(1000);
 layer_set_hidden((Layer *)&text_creditLine1_layer, true);
 layer_set_hidden((Layer *)&text_creditLine2_layer, true);
 
 string_format_time(time_text, sizeof(time_text), time_format, t->tick_time);
/* if (!clock_is_24h_style() && (time_text[0] == '0')) 
 {
             memmove(time_text, &time_text[1], sizeof(time_text) - 1);
 } */

text_layer_set_text(&text_time_layer, time_text);

}

//dealloccation when watchface is close
void handle_deinit(AppContextRef ctx) {
        (void)ctx;

      bmp_deinit_container(&background_image);
      //  fonts_unload_custom_font(batman_letters_15);
      //  fonts_unload_custom_font(batman_letters_20);
     //   fonts_unload_custom_font(batman_numbers_40);
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
