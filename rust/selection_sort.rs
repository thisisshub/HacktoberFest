fn selection_sort(array: &mut [i32]) {
    let len = array.len();
    for i in 0..len {
        let min = (i..len).min_by_key(|x| array[*x])
                          .unwrap();
        array.swap(min, i);
    }
}

fn main() {

    let mut values = [ 5, 8, 4, 1, 7, 2, 3, 6 ];
    println!("Hello, world! The value is {:?}", values);

    selection_sort(&mut values);
    println!("Hello, world! The value is {:?}", values);
}