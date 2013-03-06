//============================================================================
// Name        : merge.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "heap.h"
using namespace std;

int main(int argc)
{
  FILE *finlist, *foutlist;  /* files with lists of in/output file names */
  int memSize;             /* available memory for merge buffers (in bytes) */
  int maxDegree, degree;   /* max allowed merge degree, and actual degree */
  int numFiles = 0;        /* # of output files that are generated */
  char *bufSpace;
  char filename[1024];
  int i;

  //  recSize = atoi(argv[1]);
  // recSize is the posting size, contains docid and freq
    recSize = 8;
  //  memSize = atoi(argv[2]);
  // memSize is the total memory assigned to ioBufs
    memSize = 6*100000;
  //  memSize = 3*100;
    bufSpace = (char *) malloc(memSize);
  //  maxDegree = atoi(argv[3]);
  // masDegree is the number of files read in
  maxDegree = 3;
  ioBufs = (buffer *) malloc((maxDegree + 1) * sizeof(buffer));
  heap.arr = (int *) malloc((maxDegree + 1) * sizeof(int));
  heap.cache = (char *) malloc(maxDegree * recSize);

  finlist = fopen64("list.dat", "r");

//  foutlist = fopen64("list2.dat", "w");

  //streambuf is for the postings structure
  StreamBuffer streambuf(2000000);
  //streambuf1 is for the index structure
  StreamBuffer streambuf1(1000000);
//  StreamBuffer streambuf(400);
//  StreamBuffer streambuf1(500);
  streambuf1.setfilename("index");


  while (!feof(finlist))
  {
    for (degree = 0; degree < maxDegree; degree++)
    {
      fscanf(finlist, "%s", filename);
      if (feof(finlist)) break;
      ioBufs[degree].f = fopen64(filename, "r");
      cout<<filename<<endl;
    }

    if (degree == 0) break;

    /* open output file (output is handled by the buffer ioBufs[degree]) */
//    sprintf(filename, "%s%d", "result", numFiles);
//    ioBufs[degree].f = fopen64(filename, "w");

    /* assign buffer space (all buffers same space) and init to empty */
    bufSize = memSize / ((degree + 1) * recSize);
    for (i = 0; i <= degree; i++)
    {
      ioBufs[i].buf = &(bufSpace[i * bufSize * recSize]);
      ioBufs[i].curRec = 0;
      ioBufs[i].numRec = 0;
    }

    /* initialize heap with first elements. Heap root is in heap[1] (not 0) */
    heap.size = degree;
    for (i = 0; i < degree; i++)  heap.arr[i+1] = nextRecord(i);
    for (i = degree; i > 0; i--)  heapify(i);

    /* now do the merge - ridiculously simple: do 2 steps until heap empty */
    while (heap.size > 0)
    {
      /* copy the record corresponding to the minimum to the output */
      writeRecord(&(ioBufs[degree]), heap.arr[1], streambuf, streambuf1);

      /* replace minimum in heap by the next record from that file */
      if (nextRecord(heap.arr[1]) == -1)
        heap.arr[1] = heap.arr[heap.size--];     /* if EOF, shrink heap by 1 */
      if (heap.size > 1)  heapify(1);
    }

    /* flush output, add output file to list, close in/output files, and next */
    writeRecord(&(ioBufs[degree]), -1, streambuf, streambuf1);
//    fprintf(foutlist, "%s\n", filename);
    for (i = 0; i < degree; i++)  
    {
        cout<<"close:"<<i<<endl;
        fclose(ioBufs[i].f);
    }
    numFiles++;
  }
  streambuf.savetofile();
  streambuf1.savetofile();
  fclose(finlist);
//  fclose(foutlist);
  free(ioBufs);
  free(heap.arr);
  free(heap.cache);
}



