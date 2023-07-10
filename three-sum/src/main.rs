fn main() {
    let nums = vec![-1, 0, 1, 2, -1, -4];
    let result = three_sum(nums);
    dbg!(result);
}

fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
    use std::collections::HashSet;
    nums.sort();

    let mut result: HashSet<Vec<i32>> = HashSet::new();

    for i in 0..nums.len() - 1 {
        let mut right_ptr = nums.len() - 1;
        let mut left_ptr = i + 1;

        while left_ptr < right_ptr {
            let n1 = nums[i];
            let n2 = nums[left_ptr];
            let n3 = nums[right_ptr];
            let sum = n1 + n2 + n3;
            if sum == 0 {
                result.insert(vec![n1, n2, n3]);
                left_ptr += 1;
                right_ptr -= 1;
            } else if sum < 0 {
                left_ptr += 1;
            } else {
                right_ptr -= 1;
            }
        }
    }

    return result.iter().map(|el| el.to_owned()).collect::<Vec<Vec<i32>>>();
}

