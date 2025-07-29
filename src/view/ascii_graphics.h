#include <vector>
#include <string>

// This code was originally provided by the CS247 course instructors
// But was altered slightly to better match our use case

//SIMPLE_GRAPHICS = 0 displays a fancy style.
//SIMPLE_GRAPHICS = 1 displays the style shown in the project specification's examples
//You are encouraged to use SIMPLE_GRAPHICS = 0, but some terminals may not like it.
#define SIMPLE_GRAPHICS 0

typedef std::vector<std::string> card_template_t;

card_template_t display_basic_card(std::string name, int cost, std::string type, std::string description);
card_template_t display_tl_bl_br_card(std::string name, int cost, std::string type, std::string description, 
                                        std::string top_left, std::string bottom_left, std::string bottom_right);
card_template_t display_bl_br_card(std::string name, int cost, std::string type, std::string description, 
                                    std::string bottom_left, std::string bottom_right);
card_template_t display_tl_br_card(std::string name, int cost, std::string type, std::string description,
                                    std::string top_left, std::string bottom_right);
card_template_t display_player_card_given(int player_num,std::string name,int life,int mana);

extern const card_template_t CARD_TEMPLATE_BL_BR;
extern const card_template_t CARD_TEMPLATE_TL_BL_BR;
extern const card_template_t CARD_TEMPLATE_BORDER;
extern const card_template_t CARD_TEMPLATE_TL_BR;
extern const card_template_t CARD_TEMPLATE;
extern const card_template_t CARD_TEMPLATE_EMPTY;

extern const card_template_t PLAYER_1_TEMPLATE;
extern const card_template_t PLAYER_2_TEMPLATE;

extern const card_template_t CENTRE_GRAPHIC;

extern const std::string EXTERNAL_BORDER_CHAR_UP_DOWN;
extern const std::string EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
extern const std::string EXTERNAL_BORDER_CHAR_TOP_LEFT;
extern const std::string EXTERNAL_BORDER_CHAR_TOP_RIGHT;
extern const std::string EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
extern const std::string EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT;
