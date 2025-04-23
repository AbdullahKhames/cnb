export default class Heap {

    #data_list;
    #size;
  
    constructor() {
      this.#data_list = []
      this.#size = 0;
    }
  
  
    insert(data){
      var i = this.#size;
      this.#data_list[i] = data;
      this.#size++;
  
      var parent_index =  Math.floor( (i-1)/2 );
      while(i>=0 && this.#data_list[i] < this.#data_list[parent_index]){ 
        this.#data_list[i] = this.#data_list[parent_index];
        this.#data_list[parent_index] = data;
        i = parent_index;
        parent_index =  Math.floor( (i-1)/2 );
      }
    }
  
    pop(){
      if(this.#size == 0) return null;
      var i = 0;
      var data = this.#data_list[i];
  
      this.#data_list[i] = this.#data_list[this.#size - 1];
      this.#data_list[this.#size - 1] = null;
      this.#size--;
  
      var left_index = 2 * i + 1;
      while (left_index < this.#size){
        
        var right_index = 2 * i + 2;
  
        var smaller_index = left_index;
        if( this.#data_list[right_index] != null &&
          this.#data_list[right_index] < this.#data_list[left_index]){
          smaller_index = right_index;
        }
  
        if( this.#data_list[smaller_index] >= this.#data_list[i] ){
          break;
        }
  
        var temp = this.#data_list[i];
        this.#data_list[i] = this.#data_list[smaller_index];
        this.#data_list[smaller_index] = temp;
  
        i = smaller_index;
        left_index = 2 * i + 1;
        
      }
  
      return data;
      
    }
    
  
    print() {
      var print_data = "";
      for (var i = 0; i < this.#size; i++) {
        print_data += this.#data_list[i] + " - ";
      }
      console.log(print_data);
    }
    size() {
      return this.#size;
    }
  
  
    draw() {
  
      var levels_count = Math.log2(this.#size) + 1;
      var line_width = Math.pow(2, levels_count - 1);
  
      var j = 0;
      for (var i = 0; i < levels_count; i++) {
  
        var nodes_count = Math.pow(2, i);
        var space = Math.ceil(line_width - nodes_count / 2);
        var space_between = Math.ceil(levels_count / nodes_count);
        space_between = space_between < 1 ? 1 : space_between;
        var k = j;
        var str = " ".repeat(space + space_between);
        for (; j < k + nodes_count; j++) {
          if (j == this.#size) {
            break;
          }
          if (this.#data_list[j]) {
            str += this.#data_list[j] + " ".repeat(space_between);
          }
        }
        str += " ".repeat(space) + "\n";
        console.log(str);
      }
    }
  
  
  }
