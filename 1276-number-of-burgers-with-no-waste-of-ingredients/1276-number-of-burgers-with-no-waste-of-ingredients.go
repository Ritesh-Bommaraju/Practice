func numOfBurgers(ts int, cs int) []int {
    if ts%2==1 || ts/2<cs || ts/4>cs {
        return []int{}
    } 
    return []int{ts/2-cs, 2*cs-ts/2}
}