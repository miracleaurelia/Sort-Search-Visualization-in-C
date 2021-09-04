#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

char word[6]={'s','p','l','i','t'};
char num[20][3]={"1","3","5","7","11","13","15","17","19","23","29","31","37","41","43","47"};
char idx[20][3]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14"};
char numuni[9][4]={"13","21","34","55","69","73","84","101"};

void quickSort();
void selectionSort();
void bubbleSort();
void binarySearch();
void interpolation();

int main() {
	int gd,gm;
	detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(WHITE);
    while (1) {
    	outtextxy(150,30,"Sorting & Searching");
	    outtextxy(188,60,"Visualization");
	    outtextxy(150,140,"Choose one:");
	    outtextxy(130,180,"1. Bubble Sort");
	    outtextxy(130,210,"2. Selection Sort");
	    outtextxy(130,240,"3. Quick Sort");
	    outtextxy(130,270,"4. Binary Search");
	    outtextxy(130,300,"5. Interpolation Search");
	    outtextxy(130,330,"6. Exit");
    	int mode=getch();
    	cleardevice();
    	if (mode=='1') {
	    	bubbleSort();
	    	getch();
	    	cleardevice();
		}
		else if (mode=='2') {
			selectionSort();
			getch();
			cleardevice();
		}
		else if (mode=='3') {
			quickSort();
			getch();
			cleardevice();
		}
		else if (mode=='4') {
			binarySearch();
			getch();
			cleardevice();
		}
		else if (mode=='5') {
			interpolation();
			getch();
			cleardevice();
		}
		else if (mode=='6') break;
	}
	closegraph();
	return 0;
}

void quickSort() {
    int i,j;
	outtextxy(60,80,"Determine pivot");
	outtextxy(60,150,"ASCII of letters < Pivot");
	outtextxy(60,180,"in the left side of pivot");
	outtextxy(60,230,"ASCII of letters > Pivot");
	outtextxy(60,260,"in the right side of pivot");
	delay(6000);
	cleardevice();
    char str[2];
    for (j=0;j<5;j++) {                       
		rectangle(j*35+200,200,j*35+30+200,30+200);
        sprintf(str,"%c",word[j]);       
        outtextxy(j*35+8+200,8+200,str);
    }
    delay(2000);
	outtextxy(206,70+60,"|");
	outtextxy(206,85+60,"|");
	outtextxy(200,160,"\\/");
	outtextxy(180,100,"Pivot");
	delay(1000);
	outtextxy(200+140,48+200,"/\\");
	outtextxy(206+140,63+200,"|");
	delay(2000);
	outtextxy(190+140,300,"t > s");
	delay(3000);
	outtextxy(190+140,300,"     ");
	for (i=0;i<=35;i++) {
    	outtextxy(200+140-i,48+200,"/\\");
		outtextxy(206+140-i,63+200,"|");
	    delay(10);
	}
	delay(1000);
	outtextxy(190+100,300,"i < s");
	delay(3000);
	outtextxy(200+140-i,48+200,"      ");
	outtextxy(206+140-i,63+200,"   ");
	outtextxy(190+100,300,"     ");
	for (i=0;i<50;i++) {
		outtextxy(0*35+8+200,8+200+i,"s");
		outtextxy(3*35+8+200,8+200+i,"i");
		delay(10);
	}
	for (i=0;i<=35*3;i++) {
		outtextxy(0*35+8+200+i,8+200+49,"s");
		outtextxy(3*35+8+200-i,8+200+49,"i");
		delay(10);
	}
	for (i=0;i<50;i++) {
		outtextxy(0*35+8+200+35*3,8+200+49-i,"s");
		outtextxy(3*35+8+200-35*3,8+200+49-i,"i");
		delay(10);
	}
	rectangle(0*35+200,200,0*35+30+200,30+200);
	rectangle(3*35+200,200,3*35+30+200,30+200);
	for (i=0;i<=35*3;i++) {
    	outtextxy(206+i,70+60,"|");
		outtextxy(206+i,85+60,"|");
		outtextxy(200+i,160,"\\/");
		outtextxy(180+i,100,"Pivot");
	    delay(10);
	}
	delay(1000);
    for (i=0;i<=35;i++) {
    	outtextxy(200+i,48+200,"/\\");
		outtextxy(206+i,63+200,"|");
	    delay(10);
	}
	outtextxy(200+35,300,"p < s");
	delay(3000);
	outtextxy(200+35,300,"     ");
	for (i=0;i<=35;i++) {
    	outtextxy(200+35+i,48+200,"/\\");
		outtextxy(206+35+i,63+200,"|");
	    delay(10);
	}
	outtextxy(200+70,300,"l < s");
	delay(3000);
	outtextxy(200+70,300,"     ");
	delay(1000);
	outtextxy(15,300,"Goal has been reached");
	outtextxy(15,330,"array is now partitioned");
	outtextxy(15,360,"s and t are in the right position now");
	delay(3000);
	for (i=0;i<35;i++) {     
		delay(10);
        cleardevice();        
		rectangle(0*35+200-i,200,0*35+30+200-i,30+200);
		rectangle(1*35+200-i,200,1*35+30+200-i,30+200);
		rectangle(2*35+200-i,200,2*35+30+200-i,30+200);
		rectangle(3*35+200,200,3*35+30+200,30+200);
		rectangle(4*35+200+i,200,4*35+30+200+i,30+200);
        outtextxy(0*35+8+200-i,8+200,"i");
        outtextxy(1*35+8+200-i,8+200,"p");
        outtextxy(2*35+8+200-i,8+200,"l");
        outtextxy(3*35+8+200,8+200,"s");
        outtextxy(4*35+8+200+i,8+200,"t");
    }
	delay(3000);
	outtextxy(50,300,"                                ");
    outtextxy(206-35,70+60,"|");
	outtextxy(206-35,85+60,"|");
	outtextxy(200-35,160,"\\/");
	outtextxy(180-35,100,"Pivot");
	delay(3000);
    outtextxy(200+35,48+200,"/\\");
	outtextxy(206+35,63+200,"|");
	delay(2000);
	outtextxy(220,300,"l > i");
	delay(3000);
	outtextxy(220,300,"     ");
	for (i=0;i<35;i++) {
		outtextxy(200+35-i,48+200,"/\\");
		outtextxy(206+35-i,63+200,"|");
	}
	outtextxy(220-35,300,"p > i");
	delay(3000);
	outtextxy(220-35,300,"     ");
	delay(1000);
	outtextxy(15,300,"Goal has been reached");
	outtextxy(15,330,"array is now partitioned");
	outtextxy(15,360,"i is in the right position now");
	delay(3000);
	for (i=0;i<35;i++) {     
		delay(10);
        cleardevice();        
		rectangle(0*35+200-35-i,200,0*35+30+200-35-i,30+200);
		rectangle(1*35+200-35,200,1*35+30+200-35,30+200);
		rectangle(2*35+200-35,200,2*35+30+200-35,30+200);
		rectangle(3*35+200,200,3*35+30+200,30+200);
		rectangle(4*35+200+35,200,4*35+30+200+35,30+200);
        outtextxy(0*35+8+200-35-i,8+200,"i");
        outtextxy(1*35+8+200-35,8+200,"p");
        outtextxy(2*35+8+200-35,8+200,"l");
        outtextxy(3*35+8+200,8+200,"s");
        outtextxy(4*35+8+200+35,8+200,"t");
    }
    delay(3000);
    outtextxy(50,300,"                                ");
    outtextxy(206,70+60,"|");
	outtextxy(206,85+60,"|");
	outtextxy(200,160,"\\/");
	outtextxy(180,100,"Pivot");
	delay(3000);
	outtextxy(200+35,48+200,"/\\");
	outtextxy(206+35,63+200,"|");
	delay(2000);
	outtextxy(220,300,"l < p");
	delay(3000);
	outtextxy(200+35,48+200,"   ");
	outtextxy(206+35,63+200,"  ");
	outtextxy(220,300,"      ");
	for (i=0;i<50;i++) {
		outtextxy(1*35+8+200-35,8+200+i,"p");
		outtextxy(2*35+8+200-35,8+200+i,"l");
		delay(10);
	}
	for (i=0;i<=35;i++) {
		outtextxy(1*35+8+200-35+i,8+200+49,"p");
		outtextxy(2*35+8+200-35-i,8+200+49,"l");
		delay(10);
	}
	for (i=0;i<50;i++) {
		outtextxy(1*35+8+200-35+35,8+200+49-i,"p");
		outtextxy(2*35+8+200-35-35,8+200+49-i,"l");
		delay(10);
	}
	rectangle(1*35+200-35,200,1*35+30+200-35,30+200);
	rectangle(2*35+200-35,200,2*35+30+200-35,30+200);
	delay(1000);
	outtextxy(15,300,"Goal has been reached");
	outtextxy(15,330,"array is now partitioned");
	outtextxy(15,360,"l and p are in the right position now");
	delay(3000);
	for (i=0;i<35;i++) {     
		delay(10);
        cleardevice();        
		rectangle(0*35+200-35-35-i,200,0*35+30+200-35-35-i,30+200);
		rectangle(1*35+200-35-i,200,1*35+30+200-35-i,30+200);
		rectangle(2*35+200-35,200,2*35+30+200-35,30+200);
		rectangle(3*35+200,200,3*35+30+200,30+200);
		rectangle(4*35+200+35,200,4*35+30+200+35,30+200);
        outtextxy(0*35+8+200-35-35-i,8+200,"i");
        outtextxy(1*35+8+200-35-i,8+200,"l");
        outtextxy(2*35+8+200-35,8+200,"p");
        outtextxy(3*35+8+200,8+200,"s");
        outtextxy(4*35+8+200+35,8+200,"t");
    }
    delay(2000);
    outtextxy(200,300,"SORTED !");
}

void selectionSort() {
	int i,j;
	char str[2];
    for (j=0;j<5;j++) {                       
		rectangle(j*35+200,200,j*35+30+200,30+200);
        sprintf(str,"%c",word[j]);       
        outtextxy(j*35+8+200,8+200,str);
    }
    delay(2000);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(0,0,"Blue : current minimum");
    outtextxy(0,20,"Red : current item");
    setcolor(BLUE);
	outtextxy(206,70+60,"|");
	outtextxy(206,85+60,"|");
	outtextxy(200,160,"\\/");
	setcolor(RED);
	outtextxy(200,48+200,"/\\");
	outtextxy(206,63+200,"|");
	delay(2000);
	for (i=0;i<=35;i++) {
		outtextxy(200+i,48+200,"/\\");
		outtextxy(206+i,63+200,"|");
		delay(10);
	}
	delay(2000);
	setcolor(BLUE);
	for (i=0;i<=35;i++) {
		outtextxy(206+i,70+60,"|");
		outtextxy(206+i,85+60,"|");
		outtextxy(200+i,160,"\\/");
		delay(10);
	}
	delay(2000);
	setcolor(RED);
	for (i=0;i<=35;i++) {
		outtextxy(200+35+i,48+200,"/\\");
		outtextxy(206+35+i,63+200,"|");
		delay(10);
	}
	delay(2000);
	setcolor(BLUE);
	for (i=0;i<=35;i++) {
		outtextxy(206+35+i,70+60,"|");
		outtextxy(206+35+i,85+60,"|");
		outtextxy(200+35+i,160,"\\/");
		delay(10);
	}
	delay(2000);
	setcolor(RED);
	for (i=0;i<=35;i++) {
		outtextxy(200+35+35+i,48+200,"/\\");
		outtextxy(206+35+35+i,63+200,"|");
		delay(10);
	}
	delay(2000);
	setcolor(BLUE);
	for (i=0;i<=35;i++) {
		outtextxy(206+35+35+i,70+60,"|");
		outtextxy(206+35+35+i,85+60,"|");
		outtextxy(200+35+35+i,160,"\\/");
		delay(10);
	}
	delay(2000);
	setcolor(RED);
	for (i=0;i<=35;i++) {
		outtextxy(200+35+70+i,48+200,"/\\");
		outtextxy(206+35+70+i,63+200,"|");
		delay(10);
	}
	delay(2000);
	setcolor(WHITE);
	outtextxy(15,300,"Swap the first index of the unsorted");
	outtextxy(15,320,"array with the current minimum");
	delay(4000);
	outtextxy(15,300,"                                    ");
	outtextxy(15,320,"                              ");
	outtextxy(200+140,48+200,"    ");
	outtextxy(206+140,63+200," ");
	outtextxy(206+105,70+60," ");
	outtextxy(206+105,85+60," ");
	outtextxy(200+105,160,"    ");
	for (i=0;i<=50;i++) {
		outtextxy(0*35+8+200,8+200+i,"s");
		outtextxy(3*35+8+200,8+200+i,"i");
		delay(10);
	}
	for (i=0;i<=35*3;i++) {
		outtextxy(0*35+8+200+i,8+200+50,"s");
		outtextxy(3*35+8+200-i,8+200+50,"i");
		delay(10);
	}
	for (i=0;i<=50;i++) {
		outtextxy(0*35+8+200+35*3,8+200+50-i,"s");
		outtextxy(3*35+8+200-35*3,8+200+50-i,"i");
		delay(10);
	}
	rectangle(0*35+200,200,0*35+30+200,30+200);
	rectangle(3*35+200,200,3*35+30+200,30+200);
	delay(2000);
	for (i=0;i<=35;i++) {     
		delay(10);
        cleardevice();        
		rectangle(0*35+200-i,200,0*35+30+200-i,30+200);
		rectangle(1*35+200,200,1*35+30+200,30+200);
		rectangle(2*35+200,200,2*35+30+200,30+200);
		rectangle(3*35+200,200,3*35+30+200,30+200);
		rectangle(4*35+200,200,4*35+30+200,30+200);
        outtextxy(0*35+8+200-i,8+200,"i");
        outtextxy(1*35+8+200,8+200,"p");
        outtextxy(2*35+8+200,8+200,"l");
        outtextxy(3*35+8+200,8+200,"s");
        outtextxy(4*35+8+200,8+200,"t");
    }
    outtextxy(0,0,"Blue : current minimum");
    outtextxy(0,20,"Red : current item");
    setcolor(RED);
    outtextxy(200+35,48+200,"/\\");
	outtextxy(206+35,63+200,"|");
	setcolor(BLUE);
	outtextxy(206+35,70+60,"|");
	outtextxy(206+35,85+60,"|");
	outtextxy(200+35,160,"\\/");
	delay(3000);
	setcolor(RED);
	for (i=0;i<=35;i++) {
		outtextxy(200+35+i,48+200,"/\\");
		outtextxy(206+35+i,63+200,"|");
		delay(10);
	}
	delay(2000);
	setcolor(BLUE);
	for (i=0;i<=35;i++) {
		outtextxy(206+35+i,70+60,"|");
		outtextxy(206+35+i,85+60,"|");
		outtextxy(200+35+i,160,"\\/");
		delay(10);
	}
	delay(2000);
	setcolor(RED);
	for (i=0;i<=35;i++) {
		outtextxy(200+70+i,48+200,"/\\");
		outtextxy(206+70+i,63+200,"|");
		delay(10);
	}
	delay(2000);
	for (i=0;i<=35;i++) {
		outtextxy(200+105+i,48+200,"/\\");
		outtextxy(206+105+i,63+200,"|");
		delay(10);
	}
	delay(2000);
	setcolor(WHITE);
	outtextxy(15,300,"Swap the first index of the unsorted");
	outtextxy(15,320,"array with the current minimum");
	delay(4000);
	outtextxy(15,300,"                                    ");
	outtextxy(15,320,"                              ");
	outtextxy(200+140,48+200,"    ");
	outtextxy(206+140,63+200," ");
	outtextxy(206+70,70+60," ");
	outtextxy(206+70,85+60," ");
	outtextxy(200+70,160,"    ");
	for (i=0;i<=50;i++) {
		outtextxy(1*35+8+200,8+200+i,"p");
		outtextxy(2*35+8+200,8+200+i,"l");
		delay(10);
	}
	for (i=0;i<=35;i++) {
		outtextxy(1*35+8+200+i,8+200+50,"p");
		outtextxy(2*35+8+200-i,8+200+50,"l");
		delay(10);
	}
	for (i=0;i<=50;i++) {
		outtextxy(1*35+8+200+35,8+200+50-i,"p");
		outtextxy(2*35+8+200-35,8+200+50-i,"l");
		delay(10);
	}
	rectangle(1*35+200,200,1*35+30+200,30+200);
	rectangle(2*35+200,200,2*35+30+200,30+200);
	delay(2000);
	for (i=0;i<=35;i++) {     
		delay(10);
        cleardevice();        
		rectangle(0*35+200-35,200,0*35+30+200-35,30+200);
		rectangle(1*35+200-i,200,1*35+30+200-i,30+200);
		rectangle(2*35+200,200,2*35+30+200,30+200);
		rectangle(3*35+200,200,3*35+30+200,30+200);
		rectangle(4*35+200,200,4*35+30+200,30+200);
        outtextxy(0*35+8+200-35,8+200,"i");
        outtextxy(1*35+8+200-i,8+200,"l");
        outtextxy(2*35+8+200,8+200,"p");
        outtextxy(3*35+8+200,8+200,"s");
        outtextxy(4*35+8+200,8+200,"t");
    }
    outtextxy(0,0,"Blue : current minimum");
    outtextxy(0,20,"Red : current item");
    setcolor(RED);
    outtextxy(200+70,48+200,"/\\");
	outtextxy(206+70,63+200,"|");
	setcolor(BLUE);
	outtextxy(206+70,70+60,"|");
	outtextxy(206+70,85+60,"|");
	outtextxy(200+70,160,"\\/");
	delay(3000);
	setcolor(RED);
	for (i=0;i<=35;i++) {
		outtextxy(200+70+i,48+200,"/\\");
		outtextxy(206+70+i,63+200,"|");
		delay(10);
	}
	delay(2000);
	for (i=0;i<=35;i++) {
		outtextxy(200+105+i,48+200,"/\\");
		outtextxy(206+105+i,63+200,"|");
		delay(10);
	}
	delay(2000);
	setcolor(WHITE);
	outtextxy(15,300,"current min is in 1st index of");
	outtextxy(15,320,"unsorted array, no swap needed");
	delay(4000);
	for (i=0;i<=35;i++) {     
		delay(10);
        cleardevice();        
		rectangle(0*35+200-35,200,0*35+30+200-35,30+200);
		rectangle(1*35+200-35,200,1*35+30+200-35,30+200);
		rectangle(2*35+200-i,200,2*35+30+200-i,30+200);
		rectangle(3*35+200,200,3*35+30+200,30+200);
		rectangle(4*35+200,200,4*35+30+200,30+200);
        outtextxy(0*35+8+200-35,8+200,"i");
        outtextxy(1*35+8+200-35,8+200,"l");
        outtextxy(2*35+8+200-i,8+200,"p");
        outtextxy(3*35+8+200,8+200,"s");
        outtextxy(4*35+8+200,8+200,"t");
    }
    outtextxy(0,0,"Blue : current minimum");
    outtextxy(0,20,"Red : current item");
    setcolor(RED);
    outtextxy(200+105,48+200,"/\\");
	outtextxy(206+105,63+200,"|");
	setcolor(BLUE);
	outtextxy(206+105,70+60,"|");
	outtextxy(206+105,85+60,"|");
	outtextxy(200+105,160,"\\/");
	delay(3000);
	setcolor(RED);
	for (i=0;i<=35;i++) {
		outtextxy(200+105+i,48+200,"/\\");
		outtextxy(206+105+i,63+200,"|");
		delay(10);
	}
	delay(2000);
	setcolor(WHITE);
	outtextxy(15,300,"current min is in 1st index of");
	outtextxy(15,320,"unsorted array, no swap needed.");
	outtextxy(15,350,"last element is skipped because");
	outtextxy(15,370,"it is automatically sorted");
	delay(4000);
	for (i=0;i<=35;i++) {     
		delay(10);
        cleardevice();        
		rectangle(0*35+200-35,200,0*35+30+200-35,30+200);
		rectangle(1*35+200-35,200,1*35+30+200-35,30+200);
		rectangle(2*35+200-35,200,2*35+30+200-35,30+200);
		rectangle(3*35+200-i,200,3*35+30+200-i,30+200);
		rectangle(4*35+200-i,200,4*35+30+200-i,30+200);
        outtextxy(0*35+8+200-35,8+200,"i");
        outtextxy(1*35+8+200-35,8+200,"l");
        outtextxy(2*35+8+200-35,8+200,"p");
        outtextxy(3*35+8+200-i,8+200,"s");
        outtextxy(4*35+8+200-i,8+200,"t");
    }
    outtextxy(200,300,"SORTED !");
}

void bubbleSort() {
	int i,j;
	char str[2];
    for (j=0;j<5;j++) {                       
		rectangle(j*35+200,200,j*35+30+200,30+200);
        sprintf(str,"%c",word[j]);       
        outtextxy(j*35+8+200,8+200,str);
    }
    delay(2000);
	outtextxy(363,150,"|");
	outtextxy(363,170,"|");
	outtextxy(363,235,"|");
	outtextxy(363,255,"|");
    outtextxy(200,248,"|__|");
	outtextxy(190,280,"s > p");
	outtextxy(195,300,"swap");
	delay(3000);
	outtextxy(190,280,"      ");
	outtextxy(195,300,"      ");
	for (i=0;i<=35;i++) {
		outtextxy(0*35+8+200+i,8+200,"s");
		outtextxy(1*35+8+200-i,8+200,"p");
		delay(10);
	}
	rectangle(0*35+200,200,0*35+30+200,30+200);
	rectangle(1*35+200,200,1*35+30+200,30+200);
	delay(2000);
	for (i=0;i<=35;i++) {
		outtextxy(200+i,248,"|__|");
		delay(10);
	}
	delay(1000);
	outtextxy(190+35,280,"s > l");
	outtextxy(195+35,300,"swap");
	delay(3000);
	outtextxy(190+35,280,"     ");
	outtextxy(195+35,300,"       ");
	for (i=0;i<=35;i++) {
		outtextxy(1*35+8+200+i,8+200,"s");
		outtextxy(2*35+8+200-i,8+200,"l");
		delay(10);
	}
	rectangle(1*35+200,200,1*35+30+200,30+200);
	rectangle(2*35+200,200,2*35+30+200,30+200);
	delay(2000);
	for (i=0;i<=35;i++) {
		outtextxy(200+35+i,248,"|__|");
		delay(10);
	}
	delay(1000);
	outtextxy(190+70,280,"s > i");
	outtextxy(195+70,300,"swap");
	delay(3000);
	outtextxy(190+70,280,"     ");
	outtextxy(195+70,300,"      ");
	for (i=0;i<=35;i++) {
		outtextxy(2*35+8+200+i,8+200,"s");
		outtextxy(3*35+8+200-i,8+200,"i");
		delay(10);
	}
	rectangle(2*35+200,200,2*35+30+200,30+200);
	rectangle(3*35+200,200,3*35+30+200,30+200);
	delay(2000);
	for (i=0;i<=35;i++) {
		outtextxy(200+70+i,248,"|__|");
		delay(10);
	}
	delay(1000);
	outtextxy(190+70+35,280,"s < t");
	outtextxy(186+70+35,300,"no swap");
	delay(3000);
	outtextxy(190+70+35,280,"     ");
	outtextxy(186+70+35,300,"       ");
	outtextxy(200+105,248,"       ");
	for (i=0;i<=35;i++) {
		outtextxy(363-i,150,"|");
		outtextxy(363-i,170,"|");
		outtextxy(363-i,235,"|");
		outtextxy(363-i,255,"|");
		delay(10);
	}
	delay(3000);
	outtextxy(200,248,"|__|");
	outtextxy(190,280,"p > l");
	outtextxy(195,300,"swap");
	delay(3000);
	outtextxy(190,280,"     ");
	outtextxy(195,300,"      ");
	for (i=0;i<=35;i++) {
		outtextxy(0*35+8+200+i,8+200,"p");
		outtextxy(1*35+8+200-i,8+200,"l");
		delay(10);
	}
	rectangle(0*35+200,200,0*35+30+200,30+200);
	rectangle(1*35+200,200,1*35+30+200,30+200);
	delay(2000);
	for (i=0;i<=35;i++) {
		outtextxy(200+i,248,"|__|");
		delay(10);
	}
	delay(1000);
	outtextxy(190+35,280,"p > i");
	outtextxy(195+35,300,"swap");
	delay(3000);
	outtextxy(190+35,280,"     ");
	outtextxy(195+35,300,"     ");
	for (i=0;i<=35;i++) {
		outtextxy(1*35+8+200+i,8+200,"p");
		outtextxy(2*35+8+200-i,8+200,"i");
		delay(10);
	}
	rectangle(1*35+200,200,1*35+30+200,30+200);
	rectangle(2*35+200,200,2*35+30+200,30+200);
	delay(2000);
	for (i=0;i<=35;i++) {
		outtextxy(200+35+i,248,"|__|");
		delay(10);
	}
	delay(1000);
	outtextxy(190+70,280,"p < s");
	outtextxy(186+70,300,"no swap");
	delay(3000);
	outtextxy(190+70,280,"     ");
	outtextxy(186+70,300,"       ");
	outtextxy(200+70,248,"       ");
	for (i=0;i<=35;i++) {
		outtextxy(363-35-i,150,"|");
		outtextxy(363-35-i,170,"|");
		outtextxy(363-35-i,235,"|");
		outtextxy(363-35-i,255,"|");
		delay(10);
	}
	delay(3000);
	outtextxy(200,248,"|__|");
	outtextxy(190,280,"l > i");
	outtextxy(195,300,"swap");
	delay(3000);
	outtextxy(190,280,"     ");
	outtextxy(195,300,"      ");
	for (i=0;i<=35;i++) {
		outtextxy(0*35+8+200+i,8+200,"l");
		outtextxy(1*35+8+200-i,8+200,"i");
		delay(10);
	}
	rectangle(0*35+200,200,0*35+30+200,30+200);
	rectangle(1*35+200,200,1*35+30+200,30+200);
	delay(2000);
	for (i=0;i<=35;i++) {
		outtextxy(200+i,248,"|__|");
		delay(10);
	}
	delay(1000);
	outtextxy(190+35,280,"l < p");
	outtextxy(186+35,300,"no swap");
	delay(3000);
	outtextxy(190+35,280,"     ");
	outtextxy(186+35,300,"       ");
	outtextxy(200+35,248,"       ");
	for (i=0;i<=35;i++) {
		outtextxy(363-70-i,150,"|");
		outtextxy(363-70-i,170,"|");
		outtextxy(363-70-i,235,"|");
		outtextxy(363-70-i,255,"|");
		delay(10);
	}
	delay(3000);
	outtextxy(200,248,"|__|");
	outtextxy(190,280,"i < l");
	outtextxy(186,300,"no swap");
	delay(3000);
	outtextxy(190,280,"     ");
	outtextxy(186,300,"       ");
	outtextxy(200,248,"       ");
	outtextxy(363-105,150," ");
	outtextxy(363-105,170," ");
	outtextxy(363-105,235," ");
	outtextxy(363-105,255," ");
	outtextxy(200,300,"SORTED !");
}

void binarySearch() {
	outtextxy(70,200,"Binary search is used on");
	outtextxy(165,230,"sorted array");
	delay(5000);
	cleardevice();
	int i,j;
	char str[3];
    for (j=0;j<15;j++) {                       
		rectangle(j*40+20,200,j*40+60,30+200);
		sprintf(str,"%s",num[j]);
		if (j>=0 && j<=3) {
			outtextxy(j*40+12+20,8+200,str);
		}
		else if (j==4) {
			outtextxy(j*40+15+10,8+200,str);
		}
		else {
			outtextxy(j*40+6+20,8+200,str);
		}
    }
    for (j=0;j<15;j++) {
		sprintf(str,"%s",idx[j]);
		if (j>=0 && j<=9) {
			outtextxy(j*40+12+20,8+230,str);
		}
		else {
			outtextxy(j*40+6+20,8+230,str);
		}
    }
    delay(2000);
    outtextxy(190,290+30,"Mid:");
    outtextxy(277,280+30,"0+14");
    line(275,330,345,330);
    outtextxy(296,336,"2");
    outtextxy(355,323,"=");
    outtextxy(383,323,"7");
    delay(2000);
    outtextxy(30,260,"l");
    outtextxy(310,260,"m");
    outtextxy(585,260,"r");
    delay(2000);
	circle(121+40*5,72+65,22);
    line(110+40*5,110+65,120+40*5,120+65);
    line(120+40*5,120+65,130+40*5,110+65);
    line(110+40*5,90+65,110+40*5,110+65);
    line(130+40*5,90+65,130+40*5,111+65);
    outtextxy(105+40*5,64+65,"23");
    delay(2000);
    line(110+40*5,60+65,130+40*5,80+65);
    line(110+40*5,80+65,130+40*5,60+65);
    line(110+40*5,59+65,130+40*5,79+65);
    line(110+40*5,79+65,130+40*5,59+65);
    delay(2000);
    outtextxy(300,123,"      ");
    outtextxy(300,125,"      ");
    circle(121+40*5,72+65,22);
    outtextxy(105+40*5,64+65,"23");
    outtextxy(190,290+30,"       ");
    outtextxy(277,280+30,"       ");
    outtextxy(296,336,"  ");
    outtextxy(355,323,"  ");
    outtextxy(383,323,"  ");
    outtextxy(275,330,"             ");
    outtextxy(190,320,"23 > 17");
    outtextxy(130,340,"left moves to mid+1");
    delay(2000);
    outtextxy(310,260," ");
    outtextxy(30,260," ");
	outtextxy(350,260,"l");
	delay(1000);
	outtextxy(190,320,"       ");
    outtextxy(130,340,"                   ");
    outtextxy(190,290+30,"Mid:");
    outtextxy(277,280+30,"8+14");
    line(275,330,345,330);
    outtextxy(296,336,"2");
    outtextxy(355,323,"=");
    outtextxy(383,323,"11");
    delay(2000);
    outtextxy(470,260,"m");
    for (i=0;i<=40*4;i+=5) {
    	delay(10);
    	cleardevice();
    	circle(121+40*5+i,72+65,22);
	    line(110+40*5+i,110+65,120+40*5+i,120+65);
	    line(120+40*5+i,120+65,130+40*5+i,110+65);
	    line(110+40*5+i,90+65,110+40*5+i,110+65);
	    line(130+40*5+i,90+65,130+40*5+i,111+65);
	    outtextxy(105+40*5+i,64+65,"23");
	    for (j=0;j<15;j++) {                       
			rectangle(j*40+20,200,j*40+60,30+200);
			sprintf(str,"%s",num[j]);
			if (j>=0 && j<=3) {
				outtextxy(j*40+12+20,8+200,str);
			}
			else if (j==4) {
				outtextxy(j*40+15+10,8+200,str);
			}
			else {
				outtextxy(j*40+6+20,8+200,str);
			}
    	}
	    for (j=0;j<15;j++) {
			sprintf(str,"%s",idx[j]);
			if (j>=0 && j<=9) {
				outtextxy(j*40+12+20,8+230,str);
			}
			else {
				outtextxy(j*40+6+20,8+230,str);
			}
	    }
	    outtextxy(350,260,"l");
	    outtextxy(470,260,"m");
	    outtextxy(585,260,"r");
	    outtextxy(190,290+30,"Mid:");
	    outtextxy(277,280+30,"8+14");
	    line(275,330,345,330);
	    outtextxy(296,336,"2");
	    outtextxy(355,323,"=");
	    outtextxy(383,323,"11");
	}
    delay(2000);
    line(110+40*9,60+65,130+40*9,80+65);
    line(110+40*9,80+65,130+40*9,60+65);
    line(110+40*9,59+65,130+40*9,79+65);
    line(110+40*9,79+65,130+40*9,59+65);
    delay(2000);
    outtextxy(460,123,"      ");
    outtextxy(450,125,"      ");
    circle(121+40*9,72+65,22);
    outtextxy(105+40*9,64+65,"23");
    outtextxy(190,290+30,"       ");
    outtextxy(277,280+30,"       ");
    outtextxy(296,336,"  ");
    outtextxy(355,323,"  ");
    outtextxy(383,323,"  ");
    outtextxy(275,330,"             ");
    outtextxy(190,320,"23 < 31");
    outtextxy(130,340,"right moves to mid-1");
    delay(2000);
    outtextxy(470,260," ");
	outtextxy(585,260," ");
	outtextxy(585-40*4,260,"r");
	delay(1000);
	outtextxy(190,320,"                  ");
    outtextxy(130,340,"                       ");
    outtextxy(190,290+30,"Mid:");
    outtextxy(277,280+30,"8+10");
    line(275,330,345,330);
    outtextxy(296,336,"2");
    outtextxy(355,323,"=");
    outtextxy(383,323,"9");
    delay(2000);
    outtextxy(470-80,260,"m");
    for (i=0;i<=40*2;i+=5) {
    	delay(10);
    	cleardevice();
    	circle(121+40*5+160-i,72+65,22);
	    line(110+40*5+160-i,110+65,120+40*5+160-i,120+65);
	    line(120+40*5+160-i,120+65,130+40*5+160-i,110+65);
	    line(110+40*5+160-i,90+65,110+40*5+160-i,110+65);
	    line(130+40*5+160-i,90+65,130+40*5+160-i,111+65);
	    outtextxy(105+40*5+160-i,64+65,"23");
	    for (j=0;j<15;j++) {                       
			rectangle(j*40+20,200,j*40+60,30+200);
			sprintf(str,"%s",num[j]);
			if (j>=0 && j<=3) {
				outtextxy(j*40+12+20,8+200,str);
			}
			else if (j==4) {
				outtextxy(j*40+15+10,8+200,str);
			}
			else {
				outtextxy(j*40+6+20,8+200,str);
			}
    	}
	    for (j=0;j<15;j++) {
			sprintf(str,"%s",idx[j]);
			if (j>=0 && j<=9) {
				outtextxy(j*40+12+20,8+230,str);
			}
			else {
				outtextxy(j*40+6+20,8+230,str);
			}
	    }
	    outtextxy(190,290+30,"Mid:");
    	outtextxy(277,280+30,"8+10");
    	line(275,330,345,330);
		outtextxy(296,336,"2");
    	outtextxy(355,323,"=");
    	outtextxy(383,323,"9");
	    outtextxy(350,260,"l");
	    outtextxy(470-80,260,"m");
	    outtextxy(585-40*4,260,"r");
	}
	delay(2000);
	line(110+280,135,117+280,145);
	line(117+280,145,130+280,125);
	delay(2000);
	outtextxy(190,290+30,"          ");
    outtextxy(277,280+30,"          ");
    outtextxy(275,330,"               ");
	outtextxy(296,336," ");
    outtextxy(355,323," ");
    outtextxy(383,323," ");
	outtextxy(350,260," ");
	outtextxy(470-80,260," ");
	outtextxy(585-40*4,260," ");
	outtextxy(130,300,"Number found");
	outtextxy(130,330,"index 9 is returned");
}

void interpolation() {
	int i,j;
	char str[4];
	outtextxy(40,200,"Interpolation is used on array");
	outtextxy(5,230,"that is sorted & uniformly distributed");
	delay(5000);
	cleardevice();
	outtextxy(77,70,"Formula:");
	outtextxy(77,120,"Probe = l +");
    outtextxy(277,100,"(r-l).(x-data[l])");
	line(275,125,560,125);
	outtextxy(296,140,"data[r]-data[l]");
	outtextxy(77,190,"l = leftmost position");
	outtextxy(77,220,"r = rightmost position");
	outtextxy(77,250,"x = number we search");
	outtextxy(77,280,"data[i] = data on i index");
	delay(6000);
	cleardevice();
    for (j=0;j<8;j++) {
		if (j!=7) rectangle(j*50+20+100,200-30,j*50+60+100,200);
		else rectangle(j*50+20+100,200-30,j*50+75+100,200);
		sprintf(str,"%s",numuni[j]);
		outtextxy(j*50+25+100,8+200-30,str);
    }
    for (j=0;j<8;j++) {
		sprintf(str,"%s",idx[j]);
		outtextxy(j*50+12+20+100,8+200,str);
    }
    delay(2000);
    outtextxy(132,230,"l");
	outtextxy(480,230,"r");
	delay(1000);
    outtextxy(77,290,"Probe = 0 +");
    outtextxy(277,280,"(7-0).(84-13)");
	line(275,300,485,300);
	outtextxy(320,306,"101-13");
	delay(2000);
	outtextxy(77,260+100,"      =");
	outtextxy(210,260+88,"497");
	line(207,367,267,367);
	outtextxy(216,285+88,"88");
	outtextxy(280,260+100,"="); 
	outtextxy(308,260+100,"5");
	delay(3000);
    circle(138+50*5,72+35,22);
    line(127+50*5,110+35,137+50*5,120+35);
    line(137+50*5,120+35,147+50*5,110+35);
    line(127+50*5,90+35,127+50*5,110+35);
    line(147+50*5,90+35,147+50*5,111+35);
    outtextxy(122+50*5,64+35,"84");
    delay(1000);
	line(127+50*5,56+40,147+50*5,76+40);
    line(127+50*5,76+40,147+50*5,56+40);
    line(127+50*5,55+40,147+50*5,75+40);
    line(127+50*5,75+40,147+50*5,55+40);
    delay(3000);
    outtextxy(373,95,"     ");
    outtextxy(373,100,"     ");
    circle(138+50*5,72+35,22);
    outtextxy(122+50*5,64+35,"84");
    delay(1000);
    outtextxy(77,290,"              ");
    outtextxy(277,280,"             ");
	outtextxy(275,300,"                      ");
	outtextxy(320,306,"           ");
	outtextxy(77,260+100,"       ");
	outtextxy(210,260+88,"   ");
	outtextxy(207,367,"            ");
	outtextxy(216,285+88,"  ");
	outtextxy(280,260+100," "); 
	outtextxy(308,260+100," ");
	outtextxy(190,320,"84 > 73");
    outtextxy(130,340,"left moves to probe+1");
    delay(2000);
    outtextxy(132,230," ");
    outtextxy(132+50*6,230,"l");
    delay(1000);
    outtextxy(190,320,"       ");
    outtextxy(130,340,"                     ");
    outtextxy(77,290,"Probe = 6 +");
    outtextxy(277,280,"(7-6).(84-84)");
	line(275,300,485,300);
	outtextxy(320,306,"101-84");
	delay(2000);
	outtextxy(77,260+85,"      =");
	outtextxy(210,260+85,"6");
	delay(1000);
	for (i=0;i<=50;i++) {
		delay(10);
		cleardevice();
		circle(138+50*5+i,72+35,22);
	    line(127+50*5+i,110+35,137+50*5+i,120+35);
	    line(137+50*5+i,120+35,147+50*5+i,110+35);
	    line(127+50*5+i,90+35,127+50*5+i,110+35);
	    line(147+50*5+i,90+35,147+50*5+i,111+35);
	    outtextxy(122+50*5+i,64+35,"84");
	    for (j=0;j<8;j++) {
			if (j!=7) rectangle(j*50+20+100,200-30,j*50+60+100,200);
			else rectangle(j*50+20+100,200-30,j*50+75+100,200);
			sprintf(str,"%s",numuni[j]);
			outtextxy(j*50+25+100,8+200-30,str);
	    }
	    for (j=0;j<8;j++) {
			sprintf(str,"%s",idx[j]);
			outtextxy(j*50+12+20+100,8+200,str);
	    }
	    outtextxy(132+50*6,230,"l");
	    outtextxy(480,230,"r");
	    outtextxy(77,290,"Probe = 6 +");
	    outtextxy(277,280,"(7-6).(84-84)");
		line(275,300,485,300);
		outtextxy(320,306,"101-84");
		outtextxy(77,260+85,"      =");
		outtextxy(210,260+85,"6");
	}
	delay(2000);
	line(130+50*6,105,137+50*6,115);
	line(137+50*6,115,147+50*6,95);
	delay(2000);
    outtextxy(77,290,"              ");
	outtextxy(277,280,"               ");
	outtextxy(275,300,"                        ");
	outtextxy(320,306,"        ");
	outtextxy(77,260+85,"       ");
	outtextxy(210,260+85," ");
	outtextxy(130,300,"Number found");
	outtextxy(130,330,"index 6 is returned");
}
