// my pebble function header file

TextLayer text_creditLine1_layer;
TextLayer text_creditLine2_layer;
void creditBanner()
{
  //initilizing the creditline layer
  text_layer_init(&text_creditLine1_layer, window.layer.frame);
  //setting the layer attributes
  text_layer_set_text_color(&text_creditLine1_layer, GColorBlack);
  text_layer_set_background_color(&text_creditLine1_layer, GColorClear);
  //positing attributes
  layer_set_frame(&text_creditLine1_layer.layer, GRect(15,80,150,90));
  //Font attribute
  text_layer_set_font(&text_creditLine1_layer,fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BATMAN_FOREVER_LETTERS_15)));
  layer_add_child(&window.layer, &text_creditLine1_layer.layer);
  text_layer_set_text(&text_creditLine1_layer,"Created By");
  
  //initilizing the layer  
  text_layer_init(&text_creditLine2_layer, window.layer.frame);
  //setting the layer attributes 
  text_layer_set_text_color(&text_creditLine2_layer, GColorBlack);
  text_layer_set_background_color(&text_creditLine2_layer, GColorClear);
  //positiong attribute
  layer_set_frame(&text_creditLine2_layer.layer, GRect(20,100,160,120));
  //Font attribute
  text_layer_set_font(&text_creditLine2_layer,fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BATMAN_FOREVER_LETTERS_20)));
  layer_add_child(&window.layer, &text_creditLine2_layer.layer);
  text_layer_set_text(&text_creditLine2_layer,"alokc83");
  
  
}