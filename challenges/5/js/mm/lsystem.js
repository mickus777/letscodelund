

function lsystem_step(string, rules) {
	var newstring = "";
	for (var i=0; i<string.length; i++) {
		var char = string[i];
		var replacement = rules[char];
		if (replacement) {
			newstring += replacement;
		} else {
			newstring += char;
		}
	}
	return newstring;
}

function LSystem() {
	
}