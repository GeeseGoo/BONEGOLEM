#include "ascii_graphics.h"
#include <sstream>

// This code was originally provided by the CS247 course instructors
// But was altered slightly to better match our use case

static void prepare_for_replace(card_template_t &);
static void replace_text_left(card_template_t &,char,std::string);
static void replace_text_right(card_template_t &,char,std::string);

card_template_t display_basic_card(std::string name, int cost, std::string type, std::string description){
  card_template_t out = CARD_TEMPLATE;
  prepare_for_replace(out);
  replace_text_left(out,'N',name);
  replace_text_right(out,'C', std::to_string(cost));
  replace_text_right(out,'T', type);
  replace_text_left(out,'E', description);
  return out;
}

card_template_t display_tl_bl_br_card(std::string name, int cost, std::string type, std::string description, std::string top_left, std::string bottom_left, std::string bottom_right){
  card_template_t out = CARD_TEMPLATE_TL_BL_BR;
  prepare_for_replace(out);
  replace_text_left(out,'N',name);
  replace_text_right(out,'C', std::to_string(cost));
  replace_text_right(out,'T', type);
  replace_text_left(out,'A', bottom_left);
  replace_text_right(out,'D', bottom_right);
  replace_text_left(out,'E', description);
  replace_text_left(out,'K', top_left);
  return out;
}

card_template_t display_bl_br_card(std::string name, int cost, std::string type, std::string description, std::string bottom_left, std::string bottom_right){
  card_template_t out = CARD_TEMPLATE_BL_BR;
  prepare_for_replace(out);
  replace_text_left(out,'N',name);
  replace_text_right(out,'C', std::to_string(cost));
  replace_text_right(out,'T', type);
  replace_text_left(out,'A', bottom_left);
  replace_text_right(out,'D', bottom_right);
  replace_text_left(out,'E', description);
  return out;

}

card_template_t display_tl_br_card(std::string name, int cost, std::string type, std::string description, std::string top_left, std::string bottom_right){
  card_template_t out = CARD_TEMPLATE_TL_BR;
  prepare_for_replace(out);
  replace_text_left(out,'N',name);
  replace_text_right(out,'C', std::to_string(cost));
  replace_text_right(out,'T', type);
  replace_text_right(out,'D', bottom_right);
  replace_text_left(out,'E', description);
  replace_text_left(out,'K', top_left);
  return out;
}

card_template_t given_display_player_card(int player_num,std::string name,int life,int mana) {
  std::ostringstream oss;
  card_template_t out = player_num == 1 ? PLAYER_1_TEMPLATE : PLAYER_2_TEMPLATE;
  prepare_for_replace(out);
  std::string centred_name = name;
  if (centred_name.size() < 13) {
    int extend = 13 - static_cast<int>(centred_name.size());
    oss.str("");
    for (int i=0;i<extend/2-1;i++) oss << ' ';
    oss << centred_name;
    centred_name = oss.str();
  }
  replace_text_left(out,'N',centred_name);
  oss.str("");
  oss << life;
  replace_text_right(out,'H',oss.str());
  oss.str("");
  oss << mana;
  replace_text_left(out,'M',oss.str());
  return out;
}

const card_template_t CARD_TEMPLATE_BL_BR =
#if SIMPLE_GRAPHICS == 0
      {"┏━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━┓",
       "┃ ~NNNNNNNNNNNNNNNNNNNNN~ │ ~C~ ┃",
       "┠─────────────────────────┴─────┨",
       "┃ ~TTTTTTTTTTTTTTTTTTTTTTTTTTT~ ┃",
       "┠───────────────────────────────┨",
       "┃ ~EEEEEEEEEEEEEEEEEEEEEEEEEEEE ┃",
       "┃ EEEEEEEEEEEEEEEEEEEEEEEEEEEEE ┃",
       "┃ EEEEEEEEEEEEEEEEEEEEEEEEEEEE~ ┃",
       "┠─────┐                   ┌─────┨",
       "┃ ~AA~│                   │~DD~ ┃",
       "┗━━━━━┷━━━━━━━━━━━━━━━━━━━┷━━━━━┛"};
#else
      {"|-------------------------------|",
       "| ~NNNNNNNNNNNNNNNNNNNNN~ | ~C~ |",
       "|-------------------------------|",
       "| ~TTTTTTTTTTTTTTTTTTTTTTTTTTT~ |",
       "|-------------------------------|",
       "| ~EEEEEEEEEEEEEEEEEEEEEEEEEEEE |",
       "| EEEEEEEEEEEEEEEEEEEEEEEEEEEEE |",
       "| EEEEEEEEEEEEEEEEEEEEEEEEEEEE~ |",
       "|------                   ------|",
       "| ~AA~|                   |~DD~ |",
       "|-------------------------------|"};
#endif


const card_template_t CARD_TEMPLATE_TL_BL_BR =
#if SIMPLE_GRAPHICS == 0
      {"┏━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━┓",
       "┃ ~NNNNNNNNNNNNNNNNNNNNN~ │ ~C~ ┃",
       "┠─────────────────────────┴─────┨",
       "┃ ~TTTTTTTTTTTTTTTTTTTTTTTTTTT~ ┃",
       "┠─────┬─────────────────────────┨",
       "┃ ~K~ │ ~EEEEEEEEEEEEEEEEEEEEEE ┃",
       "┠─────┘ EEEEEEEEEEEEEEEEEEEEEEE ┃",
       "┃       EEEEEEEEEEEEEEEEEEEEEE~ ┃",
       "┠─────┐                   ┌─────┨",
       "┃ ~AA~│                   │~DD~ ┃",
       "┗━━━━━┷━━━━━━━━━━━━━━━━━━━┷━━━━━┛"};
#else
      {"|-------------------------------|",
       "| ~NNNNNNNNNNNNNNNNNNNNN~ | ~C~ |",
       "|-------------------------------|",
       "| ~TTTTTTTTTTTTTTTTTTTTTTTTTTT~ |",
       "|-------------------------------|",
       "| ~K~ | ~EEEEEEEEEEEEEEEEEEEEEE |",
       "|------ EEEEEEEEEEEEEEEEEEEEEEE |",
       "|       EEEEEEEEEEEEEEEEEEEEEE~ |",
       "|------                   ------|",
       "| ~AA~|                   |~DD~ |",
       "|-------------------------------|"};
#endif

const card_template_t CARD_TEMPLATE_BORDER =
#if SIMPLE_GRAPHICS == 0
      {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓",
       "┃                               ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"};
#else
      {"|-------------------------------|",
       "|                               |",
       "|                               |",
       "|                               |",
       "|                               |",
       "|                               |",
       "|                               |",
       "|                               |",
       "|                               |",
       "|                               |",
       "|-------------------------------|"};
#endif

const card_template_t CARD_TEMPLATE_EMPTY = 
      {"                                 ",
       "                                 ",
       "                                 ",
       "                                 ",
       "                                 ",
       "                                 ",
       "                                 ",
       "                                 ",
       "                                 ",
       "                                 ",
       "                                 "};

const card_template_t CARD_TEMPLATE_TL_BR =
#if SIMPLE_GRAPHICS == 0
      {"┏━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━┓",
       "┃ ~NNNNNNNNNNNNNNNNNNNNN~ │ ~C~ ┃",
       "┠─────────────────────────┴─────┨",
       "┃ ~TTTTTTTTTTTTTTTTTTTTTTTTTTT~ ┃",
       "┠─────┬─────────────────────────┨",
       "┃ ~K~ │ ~EEEEEEEEEEEEEEEEEEEEEE ┃",
       "┠─────┘ EEEEEEEEEEEEEEEEEEEEEEE ┃",
       "┃       EEEEEEEEEEEEEEEEEEEEEE~ ┃",
       "┃                         ┌─────┨",
       "┃                         │~DD~ ┃",
       "┗━━━━━━━━━━━━━━━━━━━━━━━━━┷━━━━━┛"};
#else
      {"|-------------------------------|",
       "| ~NNNNNNNNNNNNNNNNNNNNN~ | ~C~ |",
       "|-------------------------------|",
       "| ~TTTTTTTTTTTTTTTTTTTTTTTTTTT~ |",
       "|-------------------------------|",
       "| ~K~ | ~EEEEEEEEEEEEEEEEEEEEEE |",
       "|------ EEEEEEEEEEEEEEEEEEEEEEE |",
       "|       EEEEEEEEEEEEEEEEEEEEEE~ |",
       "|                         ------|",
       "|                         |~DD~ |",
       "|-------------------------------|"};
#endif

const card_template_t CARD_TEMPLATE = 
#if SIMPLE_GRAPHICS == 0
      {"┏━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━┓",
       "┃ ~NNNNNNNNNNNNNNNNNNNNN~ │ ~C~ ┃",
       "┠─────────────────────────┴─────┨",
       "┃ ~TTTTTTTTTTTTTTTTTTTTTTTTTTT~ ┃",
       "┠───────────────────────────────┨",
       "┃ ~EEEEEEEEEEEEEEEEEEEEEEEEEEEE ┃",
       "┃ EEEEEEEEEEEEEEEEEEEEEEEEEEEEE ┃",
       "┃ EEEEEEEEEEEEEEEEEEEEEEEEEEEEE ┃",
       "┃ EEEEEEEEEEEEEEEEEEEEEEEEEEEEE ┃",
       "┃ EEEEEEEEEEEEEEEEEEEEEEEEEEEE~ ┃",
       "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"};
#else
      {"|-------------------------------|",
       "| ~NNNNNNNNNNNNNNNNNNNNN~ | ~C~ |",
       "|-------------------------------|",
       "| ~TTTTTTTTTTTTTTTTTTTTTTTTTTT~ |",
       "|-------------------------------|",
       "| ~EEEEEEEEEEEEEEEEEEEEEEEEEEEE |",
       "| EEEEEEEEEEEEEEEEEEEEEEEEEEEEE |",
       "| EEEEEEEEEEEEEEEEEEEEEEEEEEEEE |",
       "| EEEEEEEEEEEEEEEEEEEEEEEEEEEEE |",
       "| EEEEEEEEEEEEEEEEEEEEEEEEEEEE~ |",
       "|-------------------------------|"};
#endif

const card_template_t PLAYER_1_TEMPLATE =
#if SIMPLE_GRAPHICS == 0
      {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓",
       "┃                               ┃",
       "┃                               ┃",
       "┃         ~NNNNNNNNNNN~         ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┠─────┐                   ┌─────┨",
       "┃~HH~ │                   │ ~MM~┃",
       "┗━━━━━┷━━━━━━━━━━━━━━━━━━━┷━━━━━┛"};
#else
      {"|-------------------------------|",
       "|                               |",
       "|                               |",
       "|         ~NNNNNNNNNNN~         |",
       "|                               |",
       "|                               |",
       "|                               |",
       "|                               |",
       "|------                   ------|",
       "|~HH~ |                   | ~MM~|",
       "|-------------------------------|"};
#endif

const card_template_t PLAYER_2_TEMPLATE = 
#if SIMPLE_GRAPHICS == 0
      {"┏━━━━━┯━━━━━━━━━━━━━━━━━━━┯━━━━━┓",
       "┃~HH~ │                   │ ~MM~┃",
       "┠─────┘                   └─────┨",
       "┃                               ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┃          ~NNNNNNNNNNN~        ┃",
       "┃                               ┃",
       "┃                               ┃",
       "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"};
#else
      {"|-------------------------------|",
       "|~HH~ |                   | ~MM~|",
       "|------                   ------|",
       "|                               |",
       "|                               |",
       "|                               |",
       "|                               |",
       "|          ~NNNNNNNNNNN~        |",
       "|                               |",
       "|                               |",
       "|-------------------------------|"};
#endif

const std::vector<std::string> CENTRE_GRAPHIC = 
#if SIMPLE_GRAPHICS == 0
      {"╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣",
       "║                                                                                                                                                                     ║",
       "║                                                     ███████╗ ██████╗ ██████╗  ██████╗███████╗██████╗ ██╗   ██╗                                                      ║",
       "║                                                     ██╔════╝██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗╚██╗ ██╔╝                                                      ║",
       "║                                                     ███████╗██║   ██║██████╔╝██║     █████╗  ██████╔╝ ╚████╔╝                                                       ║",
       "║                                                     ╚════██║██║   ██║██╔══██╗██║     ██╔══╝  ██╔══██╗  ╚██╔╝                                                        ║",
       "║                                                     ███████║╚██████╔╝██║  ██║╚██████╗███████╗██║  ██║   ██║                                                         ║",
       "║                                                     ╚══════╝ ╚═════╝ ╚═╝  ╚═╝ ╚═════╝╚══════╝╚═╝  ╚═╝   ╚═╝                                                         ║",
       "║                                                                                                                                                                     ║",
       "╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣"};
#else
      {"|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|",
       "|                                                                 _____                                                                                               |",
       "|                                                                / ____|                                                                                              |",
       "|                                                               | (___   ___  _ __ ___ ___ _ __ _   _                                                                 |",
       "|                                                                \\___ \\ / _ \\| '__/ __/ _ \\ '__| | | |                                                                |",
       "|                                                                ____) | (_) | | | (_|  __/ |  | |_| |                                                                |",
       "|                                                               |_____/ \\___/|_|  \\___\\___|_|   \\__, |                                                                |",
       "|                                                                                                __/ |                                                                |",
       "|                                                                                               |___/                                                                 |",
       "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|"};
#endif


const std::string EXTERNAL_BORDER_CHAR_UP_DOWN =
#if SIMPLE_GRAPHICS == 0
      "║";
#else
      "|";
#endif

const std::string EXTERNAL_BORDER_CHAR_LEFT_RIGHT =
#if SIMPLE_GRAPHICS == 0
      "═";
#else
      "-";
#endif

const std::string EXTERNAL_BORDER_CHAR_TOP_LEFT =
#if SIMPLE_GRAPHICS == 0
      "╔";
#else
      "-";
#endif

const std::string EXTERNAL_BORDER_CHAR_TOP_RIGHT =
#if SIMPLE_GRAPHICS == 0
      "╗";
#else
      "-";
#endif

const std::string EXTERNAL_BORDER_CHAR_BOTTOM_LEFT =
#if SIMPLE_GRAPHICS == 0
      "╚";
#else
      "-";
#endif

const std::string EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT =
#if SIMPLE_GRAPHICS == 0
      "╝";
#else
      "-";
#endif

//Delimiter used to separate replaceable blocks
//(Displayed by ~ in the actual strings)
//Should never appear in replaced text
static const char DELIMITER = '\v';

static void replace_text_left(card_template_t &text,char flag,std::string new_text) {
  std::string::iterator sit = new_text.begin();
  bool start_replace = false;
  bool end_replace = false;
  for (card_template_t::iterator vit = text.begin(); vit != text.end(); ++vit) {
    for (std::string::iterator lit = vit->begin(); lit != vit->end(); ++lit) {
      if (*lit == DELIMITER && *(lit+1) == flag) {
        start_replace = true;
      } else if (*lit == DELIMITER) {
        end_replace = true;
      }
      if (start_replace && (*lit == flag || *lit == DELIMITER)) {
        if (sit != new_text.end()) {
          *lit = *sit;
          ++sit;
        } else {
          *lit = ' ';
        }
      }
      if (end_replace) {
        end_replace = false;
        start_replace = false;
      }
    }
  }
}

static void replace_text_right(card_template_t &text,char flag,std::string new_text) {
  std::string::reverse_iterator sit = new_text.rbegin();
  bool start_replace = false;
  bool end_replace = false;
  for (card_template_t::reverse_iterator vit = text.rbegin(); vit != text.rend(); ++vit) {
    for (std::string::reverse_iterator lit = vit->rbegin(); lit != vit->rend(); ++lit) {
      if (*lit == DELIMITER && *(lit+1) == flag) {
        start_replace = true;
      } else if (*lit == DELIMITER) {
        end_replace = true;
      }
      if (start_replace && (*lit == flag || *lit == DELIMITER)) {
        if (sit != new_text.rend()) {
          *lit = *sit;
          ++sit;
        } else {
          *lit = ' ';
        }
      }
      if (end_replace) {
        end_replace = false;
        start_replace = false;
      }
    }
  }
}

static void prepare_for_replace(card_template_t &text) {
  for (card_template_t::iterator it=text.begin();it != text.end();++it) {
    for (std::string::iterator sit = it->begin();sit != it->end();++sit) {
      if (*sit == '~') *sit = DELIMITER;
    }
  }
}
