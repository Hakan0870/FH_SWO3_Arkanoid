#include "resources.h"

void init_window_menu() {
  al_init();
  al_set_new_window_position(100, 100);
  al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_WINDOWED);
  al_set_window_title(window_menu, "Arkanoid");

  al_init_font_addon();
  al_init_ttf_addon();
}

void create_menu(int winWidth, int winHeight) {
  window_menu = al_create_display(winWidth, winHeight);
  font_caption = al_load_font("fonts/Saiyan-Sans.ttf", 60, 0);
  font_header = al_load_font("fonts/Saiyan-Sans.ttf", 96, 0);

  al_set_target_bitmap(al_get_backbuffer(window_menu));
  al_clear_to_color(black);

  al_draw_text(font_header, white, winWidth / 2, winHeight / 50, ALLEGRO_ALIGN_CENTRE, "Arkanoid");
  al_draw_text(font_caption, white, winWidth / 10, 300, ALLEGRO_ALIGN_LEFT, "Easy");
  al_draw_text(font_caption, white, winWidth / 10, 375, ALLEGRO_ALIGN_LEFT, "Medium");
  al_draw_text(font_caption, white, winWidth / 10, 450, ALLEGRO_ALIGN_LEFT, "Hard");
  al_draw_text(font_caption, red, winWidth / 10, 525, ALLEGRO_ALIGN_LEFT, "Exit");

  al_flip_display();


}
void pointer_on(float x, float y) {
  al_init_primitives_addon();

  al_draw_filled_circle(x, y, 15, red);
}
void pointer_off(float x, float y) {
  al_init_primitives_addon();

  al_draw_filled_circle(x, y, 15, black);
}


int keyboard_state() {
  al_install_keyboard();
  ALLEGRO_KEYBOARD_STATE keyboard;
  ALLEGRO_EVENT event;
  ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  al_wait_for_event(event_queue, &event);
  if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    return event.keyboard.keycode;
  return 0;
}

int game_keyboard_state() {
  al_install_keyboard();
  ALLEGRO_KEYBOARD_STATE keyboard;
  ALLEGRO_EVENT event;
  ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  al_wait_for_event(event_queue, &event);
  if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    return event.keyboard.keycode;
  return 0;

}


int main()
{
    winWidth = 1024;
    winHeight = 668;
    done = False;
    menu_option = 1;

    //menu pointer
    pointer_x = winWidth/20;
    pointer_y = 335;


    init_window_menu();
    create_menu(winWidth, winHeight);

    while (!done)
    {
        pointer_on(pointer_x, pointer_y);
        al_flip_display();
        switch (keyboard_state())
        {

        case ALLEGRO_KEY_ESCAPE:
            done = True; break;

        case ALLEGRO_KEY_UP:
            if (pointer_y>335)
            {
            pointer_off(pointer_x, pointer_y);
            pointer_y -= 75;
            menu_option--; break;
            }
            else break;


        case ALLEGRO_KEY_DOWN:
            if (pointer_y<560)
            {
            pointer_off(pointer_x, pointer_y);
            pointer_y += 75;
            menu_option++; break;
            }
            else break;

        case ALLEGRO_KEY_ENTER:
            switch (menu_option)
                {
                case 1:
                    al_destroy_display(window_menu);
                    game(easy, winWidth, winHeight, al_current_time()); break;
                case 2:
                    al_destroy_display(window_menu);
                    game(medium, winWidth, winHeight, al_current_time()); break;
                case 3:
                    al_destroy_display(window_menu);
                    game(hard, winWidth, winHeight, al_current_time()); break;
                case 4:
                    done = True; break;
                }
        }
    }
    al_destroy_display(window_menu);
}
