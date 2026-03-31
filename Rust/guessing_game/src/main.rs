use core::num;
use std::cmp::Ordering;
use std::io;
use rand::Rng;

fn main() {
    let secret_number = rand::thread_rng().gen_range(1..=100);
    println!("The secret number is {}", secret_number);

    loop {
        println!("Input your guess: ");

        let mut guess = String::new();
        io::stdin().read_line(&mut guess).expect("Failed to read");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("Your guess: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small."),
            Ordering::Equal => {
                println!("You win.");
                break;
            },
            Ordering::Greater => println!("Too large."),
            
        }
    }
}