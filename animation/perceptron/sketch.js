// A list of points we will use to "train" the perceptron
const training = [];
// A Perceptron object
let perceptron;

// We will train the perceptron with one "Point" object at a time
let count = 0;

// The function to describe a line
function f(x) {
	const y = 0.6 * x + 0.2;
	return y;
}

function setup() {
	createCanvas(640, 240);

	// The perceptron has 3 inputs -- x, y, and bias
	// Second value is "Learning Constant"
	perceptron = new Perceptron(3, 0.001); // Learning Constant is low just b/c it's fun to watch, this is not necessarily optimal

	// Create a random set of training points and calculate the "known" answer
	for (let i = 0; i < 500; i++) {
		const x = random(1);
		const y = random(1);
		let answer = 1;
		if (y < f(x)) {
			answer = -1;
		}
		training[i] = {
			input: [x, y, 1],
			output: answer,
		};
	}
}

function draw() {
	background(255);

	// Draw the line
	strokeWeight(1);
	stroke(0);
	line(0 * width, f(0) * height, 1 * width, f(1) * height);

	// Draw the line based on the current weights
	// Formula is weights[0]*x + weights[1]*y + weights[2] = 0
	stroke(0);
	strokeWeight(2);
	const weights = perceptron.weights;
	y1 = (-weights[2] - weights[0] * 0) / weights[1];
	y2 = (-weights[2] - weights[0] * 1) / weights[1];
	line(0, y1 * height, width, y2 * height);

	// Train the Perceptron with one "training" point at a time
	for (let i = 0; i < 5; i++) {
		perceptron.train(training[count].input, training[count].output);
		count = (count + 1) % training.length;
	}
	// Draw all the points based on what the Perceptron would "guess"
	// Does not use the "known" correct answer
	for (let i = 0; i < training.length; i++) {
		stroke(0);
		strokeWeight(1);
		fill(127);
		const guess = perceptron.feedforward(training[i].input);
		if (guess > 0) noFill();

		const x = training[i].input[0] * width;
		const y = training[i].input[1] * height;
		circle(x, y, 8);
	}
}
