//# BMHS - C
#include <stdio.h>
#include <string.h>
#include <time.h>

void bmhs(char* text, int textLength, char* pattern, int patternLength) {
  int maxChar = 256;
  int displacement[maxChar];
  // Assign default value to all letters
  for (int j = 0 ; j < maxChar; j++) {
    displacement[j] = patternLength + 1;
  }
  // Pattern letters shift value
  // Since the index starts at 0, it is not necessary to add 1
  for (int letterIndex = 0; letterIndex < patternLength; letterIndex++) {
    displacement[pattern[letterIndex]] =  patternLength - letterIndex;
  }

  // Adjust index to avoid out of bound error
  int i = patternLength - 1;
  
  while (i < textLength) {
    int textLetterIndex = i; 
    int patternLetterIndex = patternLength - 1;

    // Compare from right to left
    while ((patternLetterIndex >= 0) && (text[textLetterIndex] == pattern[patternLetterIndex])) { 
      patternLetterIndex--;
      textLetterIndex--;
    }
    
    // Match found in all pattern letters 
    if (patternLetterIndex < 0) {
      printf("Match from position %d to position %d", textLetterIndex + 1, textLetterIndex + patternLength); 
    }
    // Shift the text pattern 
    i = i + displacement[text[textLetterIndex+1]]; 
  }
}


///////////////main//////////////////

int main() {
  bmhs("javacjavacjavac", 15, "java", 4);


  FILE *fpt;
  double times[] = {0.0, 0.0, 0.0, 0.0, 0.0};
  clock_t start, end;
  double execution_time;
  size_t textsize, patternsize;
  start = clock();

  // Text with 500 caracters
  char text500[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque vel diam lobortis magna viverra hendrerit in mattis quam. Curabitur dapibus mi erat, a lacinia augue bibendum cursus. Duis consequat placerat erat, id gravida justo vulputate ac. Phasellus dignissim massa lectus, ac accumsan neque euismod ut. Donec lorem est, porttitor eget pulvinar id, posuere sed enim. Suspendisse at dui commodo, vestibulum dolor eu, tincidunt mauris. Mauris in sodales dolor. Cras vitae maximus nibh. Fusce in ac.";
  char pattern500[] = "ipsum";
  textsize = sizeof(text500)/sizeof(text500[0]);
  patternsize = sizeof(pattern500)/sizeof(pattern500[0]); 

  bmhs(text500, textsize, pattern500, patternsize);
  end = clock();
  execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
  times[0] = execution_time;
  printf("(%zu) Time taken to execute in seconds : %f\n", textsize, execution_time);



  // Text with 1000 caracters
  char text1000[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas efficitur laoreet nulla, eget molestie quam posuere a. Aenean eget sollicitudin nulla. Curabitur pulvinar lectus sit amet nibh semper, et euismod dui tincidunt. Nam eget bibendum orci. Suspendisse eu lacus nec dui hendrerit commodo nec quis diam. Sed vehicula, nisl a maximus aliquet, erat justo consequat tortor, sed eleifend lectus quam vel ipsum. Morbi sit amet leo ut sem finibus facilisis vel ac ligula. Nullam in eros ornare, ullamcorper ipsum et, placerat augue. Vestibulum vitae ligula a eros tempus convallis quis sed diam.Sed vel iaculis nunc, sed ultrices dolor. Mauris pulvinar elit augue, vel maximus nunc consectetur sit amet. In finibus, diam quis commodo feugiat, erat sapien aliquam enim, sit amet sodales eros velit vel sapien. Nunc ullamcorper ultricies orci in suscipit. Aliquam erat volutpat. Phasellus lacinia turpis et molestie aliquam. Pellentesque ac vehicula nisi. Fusce a odio maximus, consequat massa nisi.";
  char pattern1000[] = "ipsum";
  textsize = sizeof(text1000)/sizeof(text1000[0]);
  patternsize = sizeof(pattern1000)/sizeof(pattern1000[0]); 

  start = clock();
  bmhs(text1000, textsize, pattern1000, patternsize);
  end = clock();
  execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
  times[1] = execution_time;
  printf("(%zu) Time taken to execute in seconds : %f\n", textsize, execution_time);

  // Text with 1500 caracters
  char text1500[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque id condimentum neque. Donec in erat egestas, efficitur purus et, fringilla dui. Nam id ante in libero congue convallis nec quis urna. Quisque non ex a ante molestie laoreet. Vivamus et nunc in massa gravida tempus a lacinia est. Nullam porttitor gravida urna id suscipit. Sed ut malesuada tellus, vel eleifend odio. Suspendisse faucibus egestas dolor, quis sagittis velit cursus ac. Phasellus dignissim massa nisi, ac pharetra ante sollicitudin et. Nam nec tortor ac enim laoreet pharetra. Phasellus at scelerisque sapien. Praesent malesuada justo lectus, et auctor massa ornare id.Pellentesque condimentum rhoncus lectus, ut elementum orci iaculis sagittis. Suspendisse sit amet lorem massa. Duis varius ultrices cursus. Praesent sed nulla neque. Duis quis nunc risus. Aenean quis ligula vel eros pharetra dapibus. Mauris dui justo, porttitor quis libero sit amet, lobortis convallis lacus. Nulla id nisl id mi rutrum viverra non nec nunc. In a tempus mauris. Nam fermentum sollicitudin lorem, id fermentum enim bibendum id. Integer libero dui, semper eu molestie et, pulvinar vel quam. Donec a convallis quam. Duis quis cursus enim. Mauris diam ipsum, auctor at nulla sit amet, lacinia mollis mi. Curabitur tempus non leo quis suscipit. Vestibulum porta sodales velit, sit amet faucibus purus volutpat a.Cras malesuada enim id ipsum pellentesque varius. Phasellus a est elit. Vestibulum at accumsan tellus, id molestie nisi. Sed dui.";
  char pattern1500[] = "ipsum";
  textsize = sizeof(text1500)/sizeof(text1500[0]);
  patternsize = sizeof(pattern1500)/sizeof(pattern1500[0]); 

  start = clock();
  bmhs(text1500, textsize, pattern1500, patternsize);
  end = clock();
  execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
  times[2] = execution_time;
  printf("(%zu) Time taken to execute in seconds : %f\n", textsize, execution_time);

  // Text with 2000 caracters
  char text2000[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam felis sapien, sodales sed diam non, mollis efficitur magna. Donec at lobortis erat, a aliquet nulla. Curabitur molestie ultricies tincidunt. In tristique, turpis et vulputate feugiat, massa magna porttitor augue, eget efficitur purus sapien et urna. Etiam nisl sapien, eleifend sit amet enim vel, ultricies interdum lorem. Nulla vitae rutrum dolor, ut convallis nisl. Mauris semper commodo lacus aliquam tristique. Nam ac arcu turpis. Sed risus odio, vestibulum eget magna in, malesuada porttitor ex. Donec sit amet ex et mauris tempus condimentum. Quisque justo nunc, eleifend eu dolor in, blandit porta nunc. Nam eget risus id mi accumsan fringilla sed sed elit. Donec non turpis sed leo bibendum efficitur et vel orci. Aenean a quam varius, maximus mauris sed, pharetra orci. Aliquam suscipit felis ac turpis malesuada eleifend. Nam vel nibh non ante blandit ullamcorper.Cras aliquet purus non massa rhoncus auctor ac quis est. Proin vehicula nisl quis massa dictum ultricies. Suspendisse potenti. Pellentesque at lacus at orci scelerisque pretium et efficitur ligula. Aliquam erat volutpat. Morbi velit eros, mollis eu lorem sit amet, egestas suscipit urna. Cras urna eros, auctor ut sodales non, accumsan at ex. Sed eleifend vel urna in faucibus. Nulla suscipit nisl a porttitor iaculis. Aliquam urna sapien, auctor at fermentum vitae, maximus ac arcu.Donec consectetur leo eu dictum cursus. Etiam consequat, massa sed dapibus volutpat, velit quam placerat ligula, in placerat tellus libero in arcu. Integer feugiat ultrices lectus at laoreet. Ut condimentum tortor ac leo cursus, ac posuere leo consequat. Donec placerat ut risus sit amet aliquet. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cras blandit, mauris ut vehicula accumsan, magna mauris sagittis est, sit amet cursus ante metus euismod magna. Sed tincidunt placerat maximus. Morbi sed magna mauris. Curabitur sit quis.";
  char pattern2000[] = "ipsum";
  textsize = sizeof(text2000)/sizeof(text2000[0]);
  patternsize = sizeof(pattern2000)/sizeof(pattern2000[0]); 

  start = clock();
  bmhs(text2000, textsize, pattern2000, patternsize);
  end = clock();
  execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
  times[3] = execution_time;
  printf("(%zu) Time taken to execute in seconds : %f\n", textsize, execution_time);

  
  // Text with 5000 caracters
  char text5000[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec at felis vel nibh blandit venenatis. Donec ipsum dui, iaculis sed sollicitudin et, aliquam fringilla eros. Interdum et malesuada fames ac ante ipsum primis in faucibus. Vestibulum eu volutpat tortor, et tempus mauris. Donec et facilisis velit. Etiam nec dapibus sem, ut efficitur neque. Nulla facilisi. Pellentesque imperdiet, nunc a malesuada aliquam, diam turpis faucibus purus, id iaculis nibh tellus vel elit. Mauris vitae dolor non justo pellentesque dignissim ut et enim. Nunc id ex dui. Maecenas auctor dignissim ipsum, ut luctus nisl aliquam nec. Suspendisse finibus efficitur rhoncus. Nulla at felis rhoncus, dictum lectus vel, dictum nunc. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.Sed venenatis metus dolor, a sodales velit hendrerit at. Aenean quis elementum ipsum, a semper magna. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Pellentesque ut scelerisque nisl. Sed facilisis sollicitudin ligula, nec feugiat libero consectetur eu. Donec nulla ipsum, dictum id velit at, pretium pellentesque velit. Etiam ut mi at metus imperdiet tristique. Sed et lorem quam.Aenean feugiat fringilla molestie. Praesent aliquam est ac vulputate accumsan. In sit amet libero tempor turpis commodo elementum vitae ac dolor. Aliquam at lobortis est. Integer sagittis tortor dui. Ut vitae iaculis metus. Ut non sem gravida, blandit orci commodo, porttitor tellus. Etiam quis ultrices mauris. Etiam porta, lacus in pellentesque rutrum, massa magna iaculis enim, non placerat sem leo nec enim. Mauris consectetur magna non urna lacinia, et tristique ipsum volutpat. Proin urna mauris, rhoncus quis arcu a, dignissim tempus nulla. Praesent vestibulum urna suscipit dolor consectetur iaculis.Curabitur nec scelerisque orci. Integer venenatis consequat mattis. Vivamus dignissim posuere libero vitae imperdiet. Cras malesuada condimentum nunc in egestas. Ut vitae dui metus. Pellentesque lectus justo, vulputate quis lorem eget, consequat finibus nibh. Phasellus ut aliquet dui. Praesent dapibus, felis dapibus imperdiet scelerisque, nulla enim eleifend risus, a condimentum felis sem id magna. Ut velit urna, fermentum id lacus id, tempor gravida massa. Nulla posuere non ex at dictum. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Praesent lacinia odio nec justo sollicitudin, ac tempor massa ullamcorper. Nunc sit amet sem et nisi consectetur scelerisque in a dui. Suspendisse et turpis magna.Sed dignissim finibus nunc eget facilisis. Pellentesque feugiat, purus in bibendum pretium, quam lacus tincidunt libero, et semper lectus massa eget velit. Aenean id cursus dolor. Phasellus varius magna a cursus hendrerit. Ut molestie enim ac turpis tempor suscipit. Integer sed lacus rhoncus, dignissim justo sit amet, ultrices mauris. Vivamus vitae urna aliquet, imperdiet nibh vitae, placerat dolor. Sed condimentum sapien eget eros molestie sollicitudin. Morbi vel neque malesuada, aliquet odio non, viverra velit. Duis vitae justo eget arcu fringilla pretium a non diam. Aliquam nec urna eu sem iaculis tempus. Quisque tincidunt placerat ullamcorper. Sed eros metus, placerat interdum tincidunt sit amet, feugiat nec arcu. Nulla sed porta mi, ut elementum velit.Aenean iaculis posuere nibh, sed tempus enim cursus vel. Sed in enim ut dui blandit interdum ut eget magna. Curabitur eget dui nec nibh hendrerit volutpat. Fusce sollicitudin maximus malesuada. Quisque vitae tempor diam, at gravida diam. Ut non leo a nulla semper dignissim nec id augue. Aliquam mattis dignissim viverra. Maecenas in vestibulum orci. Morbi pharetra sed purus non malesuada.Aliquam tincidunt velit a maximus lobortis. Sed sed tincidunt nisi, eget convallis ligula. In blandit, urna et eleifend tincidunt, elit metus fringilla ligula, et lobortis nibh odio ac lectus. In pretium massa leo, eu cursus nulla dictum in. Sed lacus ex, dictum id ullamcorper a, ultrices sed justo. Fusce tempor aliquet laoreet. Aliquam erat volutpat. Nulla arcu elit, feugiat eu felis venenatis, viverra luctus tellus. Fusce viverra viverra enim at tincidunt. Vestibulum eget mauris at risus auctor rhoncus. Nam id mi in ante egestas vehicula. Nunc elit velit, mattis vitae diam et, tempor consequat eros. Praesent mattis tellus a venenatis vehicula. Suspendisse cursus efficitur ex, eget ornare risus ullamcorper sed. Nullam consequat sem nec ex euismod pellentesque. Vestibulum maximus, massa non euismod tempor, risus metus convallis nulla, in blandit risus nunc sed sem.Quisque molestie massa in tristique fermentum. Maecenas sed dignissim leo. Phasellus pretium placerat diam. Suspendisse congue purus vel quam porttitor lobortis. Duis vel ligula nisi. Morbi et nisl lacinia, ornare turpis nec, hendrerit enim. Maecenas ac iaculis justo, et dapibus lectus. Suspendisse aliquam, elit eu tincidunt fermentum, mauris erat placerat libero, ac pulvinar urna cras.";
  char pattern5000[] = "ipsum";
  textsize = sizeof(text5000)/sizeof(text5000[0]);
  patternsize = sizeof(pattern5000)/sizeof(pattern5000[0]); 

  start = clock();
  bmhs(text5000, textsize, pattern5000, patternsize);
  end = clock();
  execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
  times[4] = execution_time;
  printf("(%zu) Time taken to execute in seconds : %f\n", textsize, execution_time);

  fpt = fopen("Time.csv", "w+");
  fprintf(fpt,"Time\n");
    for(int i = 0; i<5; i++){
      fprintf(fpt,"%f\n", times[i]);
    }

  fclose(fpt);

  return 0;
}
