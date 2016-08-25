/**
 * The biggest color name supported by HTML is LightGoldenRodYellow
 * and it have 20 chars.
 */
#define MAX_COLORNAME_SIZE 25

/**
 * All structure drawable should contains this
 */
typedef struct Drawable {
  /**
   * This should accept Hexadecimal and Colors by name,
   * as long they are supported by HTML.
   */
  char * background = malloc(sizeof(char)*MAX_COLORNAME_SIZE);

  /**
   * Position X reference in HTML axis
   */
  double position_x = 0;

  /**
   * Position Y reference in HTML axis
   */
  double position_y = 0;

  /**
   * Line needs a thickness
   */
  double lineWidth = 1;
};

typedef struct Elipse {
  struct Drawable * drawable;
  double focus1;
  double focus2;
  double distance;
};

/**
 * With Arc we build a circle
 */
typedef struct Arc {
  struct Drawable * drawable;
  double radius;
  double startAngle;
  double finalAngle;
};

/**
 * Is a arc with startAngle in 0 and finalAngle in 360
 */
typedef struct Circle {
  struct Arc * arc;
}

typedef struct Line {
  struct Drawable * drawable;
  double second_position_x;
  double second_position_y;
};

typedef struct Rectangle {
  struct Drawable * drawable;
  double width;
  double heigth;
};
