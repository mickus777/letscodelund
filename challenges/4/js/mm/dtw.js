
function DTWDistance(source, target, distanceFunction) {
	var n = source.length;
	var m = target.length;

	// DTW is array[n+1][m+1] 
	var DTW = new Array(n+1);
	for (var i=0; i<n+1; i++) {
		DTW[i] = new Array(m+1);
	}

	for (var i=1; i<=n; i++) {
		DTW[i][0] = Infinity;
	}
	for (var i=1; i<=m; i++) {
		DTW[0][i] = Infinity;
	}

	DTW[0][0] = 0;

	for (var i=1; i<=n; i++) {
       for (var j=1; j<=m; j++) {
           var cost = distanceFunction(source[i-1], target[j-1]);
           DTW[i][j] = cost + minimum(DTW[i-1][j  ],    // insertion
                                      DTW[i  ][j-1],    // deletion
                                      DTW[i-1][j-1])    // match
       }
	}

	return DTW[n][m]
}

function minimum(a,b,c) {
	return Math.min(a, Math.min(b,c));
}