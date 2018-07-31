RED='\033[0;31m'
GREEN='\033[0;32m'
PURPLE='\033[0;35m'
LIGHTGREEN='\033[1;32m'
NC='\033[0m'
USER=$(users | sed s/root//g)

if brew ls --versions sdl2 > /dev/null; then
  echo "${GREEN}SDL2 is already installed${NC}"
  echo "${PURPLE}Copying SDL2 Library Files....${NC}"
  cp -R /goinfre/${USER}/.brew/Cellar/sdl2/2.0.8/include/SDL2 libraries/SDL2/
  cp -R /goinfre/${USER}/.brew/Cellar/sdl2/2.0.8/lib libraries/SDL2/lib
  echo "${LIGHTGREEN}SDL2 Library Files Successfully Copied${NC}"
else
  echo "${RED}SDL2 is not installed on this machine, Please wait while it is being installed${NC}"
  brew install sdl2
  cp -R /goinfre/${USER}/.brew/Cellar/sdl2/2.0.8/include/SDL2 libraries/dependencies
  cp -R /goinfre/${USER}/.brew/Cellar/sdl2/2.0.8/lib libraries/dependencies/lib
fi

