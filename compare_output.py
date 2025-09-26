def compare_outputs(input_file, correct_file, user_file):
    with open(input_file, "r", encoding="utf-8") as f_in, \
         open(correct_file, "r", encoding="utf-8") as f_correct, \
         open(user_file, "r", encoding="utf-8") as f_user:
        
        inputs = f_in.read().strip().splitlines()
        corrects = f_correct.read().strip().splitlines()
        users = f_user.read().strip().splitlines()

        if inputs and inputs[0].isdigit():
            inputs = inputs[1:]

        for i, (inp, cor, usr) in enumerate(zip(inputs, corrects, users), start=1):
            if cor != usr:
                print(f"Case {i}:")
                print(f" Input         : {inp}")
                print(f" User output   : {usr}")
                print(f" Correct output: {cor}")
                print("-" * 40)

if __name__ == "__main__":
    compare_outputs(
        r"C:\Users\Hoang Nguyen\Downloads\test_input.txt",
        r"C:\Users\Hoang Nguyen\Downloads\test_output.txt",
        r"C:\Users\Hoang Nguyen\Downloads\user_output.txt"
    )
