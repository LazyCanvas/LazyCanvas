#ifndef DRAWABLE_H

#define DRAWABLE_H

/**
 * The biggest color name supported by HTML is LightGoldenRodYellow
 * and it have 20 chars.
 */
#define MAX_COLORNAME_SIZE 25 * sizeof(char)

/**
 * All structure drawable should contains this
 */
typedef struct drawable {
  /**
   * This should accept Hexadecimal and Colors by name,
   * as long they are supported by HTML.
   */
  char *background;

  /**
   * Position X reference in HTML axis
   */
  double position_x;

  /**
   * Position Y reference in HTML axis
   */
  double position_y;

  /**
   * Line needs a thickness
   */
  double line_width;
}Drawable;

//TODO FIX HERE, FOCUS IS SUPPOSED TO HAVE focus_x and focus_y
typedef struct elipse {
  Drawable * drawable;
  double focus1;
  double focus2;
  double distance;
}Elipse;

/**
 * With Arc we build a circle
 */
typedef struct arc {
  Drawable *drawable;
  double radius;
  double start_angle;
  double final_angle;
}Arc;

/**
 * Is a arc with startAngle in 0 and finalAngle in 360
 */
typedef struct circle {
  Drawable * drawable;
  double radius;
}Circle;

typedef struct line {
  Drawable *drawable;
  double second_position_x;
  double second_position_y;
}Line;

typedef struct rectangle {
  Drawable * drawable;
  double coordinates;
  double heigth;
  double width;
}Rectangle;

#endif
