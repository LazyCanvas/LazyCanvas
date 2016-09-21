/**
 * The biggest color name supported by HTML is LightGoldenRodYellow
 * and it have 20 chars.
 */
#define MAX_COLORNAME_SIZE 25 * sizeof(char)

typedef enum structure_type {CIRCLE = 1, ELIPSE = 2, RECTANGLE = 3, LINE = 4, ARC = 5} StructureType;

/**
 * All structure drawable should contains this
 */
typedef struct drawable {
  StructureType object_type;
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
  Drawable * drawable;
  double radius;
  double start_angle;
  double final_angle;
  double center_x;
  double center_y;
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
  double width;
  double heigth;
}Rectangle;
