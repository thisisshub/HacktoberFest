export class Counting {
    constructor(){};
    public sort(arry: number[]): number[] {
      if (arry !== undefined) {
        let sortedIndex: number = 0;
        let output: number[] = [];
        let arrCount: number[] = [];
  
        for (let i of arry) {
  
          if (arrCount[i] === undefined) {
            arrCount[i] = 0;
          }
  
          arrCount[i] += 1;
        }
  
        for (let i = 0; i < arrCount.length; i++) {
          let count = arrCount[i];
          for (let j = 0; j < count; j++) {
            output[sortedIndex] = i;
            sortedIndex++;
          }
        }
        return output;
      }
      return [];
    }
  }
