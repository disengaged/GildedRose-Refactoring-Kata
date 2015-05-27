require 'cucumber_csteps'

CucumberCsteps.load_steps('gilded_rose', 'libgilded.so', ["features/**/*.c"])
