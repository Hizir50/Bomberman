#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>



int main(){
        int width;
        int height;

        width = MLV_get_desktop_width() - MLV_get_desktop_width() / 6;
        height = MLV_get_desktop_height() - MLV_get_desktop_height() / 6;

        MLV_create_window(
                "medium - 12 - Le résolution du bureau d'environement", 
                "résolution du bureau", width, height
        );
        MLV_draw_text(
                20, 20,
                "La résolution du bureau est de : %d X %d",
                MLV_COLOR_GREEN,
                width, height
        );
        
        MLV_actualise_window();
        MLV_wait_seconds(2);
        MLV_free_window();
        return 0;
}

