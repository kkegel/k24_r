//
// Created by Karl Kegel on 18.02.17.
//

#include "../header/pixel_operations.h"

bool redouble_resolution(unsigned char *data, int resolution, color_handler *c_h, values v){

    int square_corner_diff = v.PHW / resolution;
    int new_sqare_diff = v.PHW / (resolution * 2);
    int new_resolution = resolution * 2;
    std::array<unsigned char, 3> color;

    std::cout << "calculationg resolution " << new_resolution << std::endl;
    std::cout << "y: " << 0 << "|" << v.PHW << std::flush;

    int y = 0;

    while(y < v.PHW){

        std::cout << "\ry: " << y+1 << "|" << v.PHW << std::flush;

        for(int x = 0; x < v.PHW; x += (square_corner_diff - 1)){

            int f = 0;
            int r = std::rand() % 100;

            if(is_inner_pixel(x,y,v)){

                if(y % 2 == 0) { //inner bottom

                    while (f < 2) {

                        if (f == 0) { //right corner

                            if (r < 50) {
                                color = get_color(data, x, y,v);
                            } else if (r < 65) {
                                color = get_color(data, x + 1, y,v);
                            } else if (r < 80) {
                                color = get_color(data, x, y - 1,v);
                            } else if (r < 100 - v.SCATTERING){
                                color = get_color(data, x + 1, y - 1,v);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);
                            x++;
                            c_h -> add_to_stack(color[0], color[1], color[2]);

                        } else { //left corner

                            r = std::rand() % 100;

                            if (r < 50) {
                                color = get_color(data, x, y,v);
                            } else if (r < 65) {
                                color = get_color(data, x - 1, y,v);
                            } else if (r < 80) {
                                color = get_color(data, x, y - 1,v);
                            } else if (r < 100 - v.SCATTERING){
                                color = get_color(data, x - 1, y - 1,v);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);
                        }
                        f++;
                    }

                }else{ //inner top

                    while (f < 2) {

                        if (f == 0) { //right corner

                            if (r < 50) {
                                color = get_color(data, x, y,v);
                            } else if (r < 65) {
                                color = get_color(data, x + 1, y,v);
                            } else if (r < 80) {
                                color = get_color(data, x, y + 1,v);
                            } else if (r < 100 - v.SCATTERING){
                                color = get_color(data, x + 1, y + 1,v);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2],v);
                            x++;
                            c_h -> add_to_stack(color[0], color[1], color[2]);

                        } else { //left corner

                            r = std::rand() % 100;

                            if (r < 50) {
                                color = get_color(data, x, y,v);
                            } else if (r < 65) {
                                color = get_color(data, x - 1, y,v);
                            } else if (r < 80) {
                                color = get_color(data, x, y + 1,v);
                            } else if (r < 100 - v.SCATTERING){
                                color = get_color(data, x - 1, y + 1,v);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2],v);
                        }
                        f++;
                    }

                }

            }else if(is_bottom_stroke(x,y) && is_left_stroke(x,y)){ //bottom left corner

                if(r < v.SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);
                }

            }else if(is_bottom_stroke(x,y) && is_right_stroke(x,y,v)){ //bottom right corner

                if(r < v.SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);
                }

            }else if(is_top_stroke(x,y,v) && is_left_stroke(x,y)){ //top left corner

                if(r < v.SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x, new_sqare_diff, y - new_sqare_diff +1 , new_sqare_diff, color[0], color[1], color[2],v);
                }

            }else if(is_top_stroke(x,y,v) && is_right_stroke(x,y,v)){ //top right corner

                if(r < v.SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2],v);
                }

            }else if(is_bottom_stroke(x,y)){

                while(f < 2){

                    if(f == 0){ //right

                        if(r < 60){
                            color = get_color(data, x, y,v);
                        }if(r < 100 - v.SCATTERING){
                            color = get_color(data, x+1, y,v);
                        } else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);
                        x++;
                        c_h -> add_to_stack(color[0], color[1], color[2]);

                    }else{ //left

                        r = std::rand() % 100;

                        if(r < 60){
                            color = get_color(data, x, y,v);
                        }if(r < 100 - v.SCATTERING){
                            color = get_color(data, x-1, y,v);
                        } else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);

                    }
                    f++;
                }

            }else if(is_top_stroke(x,y,v)){

                while(f < 2){

                    if(f == 0){ //right

                        if(r < 60){
                            color = get_color(data, x, y,v);
                        }if(r < 100 - v.SCATTERING){
                            color = get_color(data, x+1, y,v);
                        }else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2],v);
                        x++;
                        c_h -> add_to_stack(color[0], color[1], color[2]);

                    }else{ //left

                        r = std::rand() % 100;

                        if(r < 60){
                            color = get_color(data, x, y,v);
                        }if(r < 100 - v.SCATTERING){
                            color = get_color(data, x-1, y,v);
                        }else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2],v);

                    }
                    f++;
                }

            }else if(is_left_stroke(x,y)){

                if(y % 2 == 0) { //square bottom

                    if (r < 60) {
                        color = get_color(data, x, y,v);
                    }
                    if (r < 100 - v.SCATTERING) {
                        color = get_color(data, x, y + 1,v);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x, new_sqare_diff, y , new_sqare_diff, color[0], color[1], color[2],v);

                }else{ //square top

                    if (r < 60) {
                        color = get_color(data, x, y,v);
                    }
                    if (r < 100 - v.SCATTERING) {
                        color = get_color(data, x, y - 1,v);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x, new_sqare_diff, y - new_sqare_diff + 1 , new_sqare_diff, color[0], color[1], color[2],v);

                }

            }else if(is_right_stroke(x,y,v)){

                if(y % 2 == 0) { //square bottom

                    if (r < 60) {
                        color = get_color(data, x, y,v);
                    }
                    if (r < 100 - v.SCATTERING) {
                        color = get_color(data, x, y + 1,v);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y , new_sqare_diff, color[0], color[1], color[2],v);

                }else{ //square top

                    if (r < 60) {
                        color = get_color(data, x, y,v);
                    }
                    if (r < 100 - v.SCATTERING) {
                        color = get_color(data, x, y - 1,v);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1 , new_sqare_diff, color[0], color[1], color[2],v);

                }

            }

            c_h -> add_to_stack(color[0], color[1], color[2]);

        }

        //std::cout << "reached line end " << y << std::endl;

        if(y % 2 == 0) {
            y += (square_corner_diff - 1);
        }else{
            y++;
        }

    }

    std::cout << " ... finished" << std::endl;

    return true;
}

bool remove_single_dots(unsigned char *data, color_handler *c_h, values v){

    std::cout << "remove single dots" << std::endl;
    std::cout << "y: " << 0 << "|" << (v.PHW - 1) << std::flush;

    int diff = v.PHW - 1;
    bool has_second = false;

    std::array<unsigned char, 3> original_color;
    std::array<unsigned char, 3> stroke_color;

    for(int y = 1; y < diff; y++){

        std::cout << "\ry: " << y << "|" << (v.PHW - 1) << std::flush;

        for(int x = 1; x < diff; x++){

            original_color = get_color(data, x, y,v);

            for(int y_i = y - 1; y_i <= y + 1; y_i++) {

                for (int x_i = x - 1; x_i <= x + 1; x_i++) {

                    if(x_i == x && y_i == y){
                        continue;
                    }

                    stroke_color = get_color(data, x_i, y_i,v);

                    if(c_h -> compare_colors(original_color, stroke_color)){

                        has_second = true;
                        break;
                    }
                }
            }

            if(!has_second){
                fill_rect(data,x,1,y,1, stroke_color[0], stroke_color[1], stroke_color[2],v);
            }else{
                has_second = false;
            }

        }

    }

    std::cout << " ... finished" << std::endl;

    return true;
}

bool smoth_x(unsigned char *data, color_handler *c_h, values v){

    std::cout << "smoth x ... " << std::flush;

    std::array<unsigned char, 3> left_color;
    std::array<unsigned char, 3> right_color;

    std::array<unsigned char, 3> n_left_color;
    std::array<unsigned char, 3> n_right_color;

    for(int y = 0; y < (v.PHW - 1); y++){

        for(int x = 1; x < (v.PHW - 1); x++){

            left_color = get_color(data, x - 1, y,v);
            right_color = get_color(data, x, y,v);

            if(! c_h->compare_colors(left_color, right_color)){

                n_left_color = c_h->mix_colors(left_color, right_color, 2, 1);
                n_right_color = c_h->mix_colors(left_color, right_color, 1, 2);

                fill_rect(data, x - 1, 1, y, 1, n_left_color[0], n_left_color[1], n_left_color[2],v);
                fill_rect(data, x, 1, y, 1, n_right_color[0], n_right_color[1], n_right_color[2],v);

            }

        }

    }

    std::cout << "finished" << std::endl;

    return true;
}

bool smoth_y(unsigned char *data, color_handler *c_h, values v){

    std::cout << "smoth y ... " << std::flush;

    std::array<unsigned char, 3> top_color;
    std::array<unsigned char, 3> bottom_color;

    std::array<unsigned char, 3> n_top_color;
    std::array<unsigned char, 3> n_bottom_color;

    for(int y = 1; y < (v.PHW - 1); y++){

        for(int x = 0; x < (v.PHW - 1); x++){

            bottom_color = get_color(data, x, y - 1,v);
            top_color = get_color(data, x, y,v);

            if(! c_h->compare_colors(bottom_color, top_color)){

                n_bottom_color = c_h->mix_colors(bottom_color, top_color, 2, 1);
                n_top_color = c_h->mix_colors(bottom_color, top_color, 1, 2);

                fill_rect(data, x, 1, y - 1, 1, n_bottom_color[0], n_bottom_color[1], n_bottom_color[2],v);
                fill_rect(data, x, 1, y, 1, n_top_color[0], n_top_color[1], n_top_color[2],v);

            }

        }

    }

    std::cout << "finished" << std::endl;

    return true;
}












