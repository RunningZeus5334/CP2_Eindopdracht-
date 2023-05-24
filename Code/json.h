#pragma once

void JSON_Fetch(char *spellname){
char CLI_buffer[1000];
snprintf(CLI_buffer, sizeof(CLI_buffer),"curl https://www.dnd5eapi.co/api/spells/%s", spellname);
FILE *fp;
char JSON_FILE[3000];
fp = popen(CLI_buffer, "r");
  
if (fp == NULL) {
  printf("Error opening CLI_buffer\n");
  return;
}else{
  fgets(JSON_FILE, sizeof(JSON_FILE)-1, fp);
  //printf(JSON_FILE);
  system("clear");    
  FILE *JSON;
  char filename[30];
  sprintf(filename, "%s.json", spellname);
  JSON = fopen(filename, "w");
  fprintf(JSON, JSON_FILE);
  fclose(JSON);
  }
  }