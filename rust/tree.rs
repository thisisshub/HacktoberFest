fn main() {
  let height = 10;
  for x in 0..=height {
    for _ in 0..=(height-x) {
      print!(" ");
    }
    for _ in 0..(x*2+1) {
      print!("*")
    }
    print!("\n");
  }

  for _ in 0..=2 {
    for _ in 0..=(height-2) {
      print!(" ");
    }
    for _ in 0..(2*2+1) {
      print!("*")
    }
    print!("\n");
  }
}