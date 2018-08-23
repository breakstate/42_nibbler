RED='\033[0;31m'
GREEN='\033[0;32m'
PURPLE='\033[0;35m'
LIGHTGREEN='\033[1;32m'
NC='\033[0m'
USER=$(users | sed s/root//g)

echo "${GREEN}============================================================${NC}"

if brew ls --versions sdl2 > /dev/null; then
  echo "${GREEN}SDL2 is already installed${NC}"
else
  echo "${RED}SDL2 is not installed on this machine, Please wait while it is being installed${NC}"
  brew install sdl2
fi

if brew ls --versions sfml > /dev/null; then
  echo "${GREEN}SFML Installed${NC}"
else
  echo "${RED}SFML is not installed on this machine, Please wait while it is being installed${NC}"
  brew install sfml
fi

echo "${GREEN}Please run 'make' in order to compile the project.${NC}"
echo "${GREEN}============================================================${NC}"