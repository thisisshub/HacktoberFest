val fibonacci = sequence {
    var current = BigDecimal(1)
    var next = BigDecimal(1)
    yield(current)
    while (true) {
        yield(next)
        val tmp = current + next
        current = next
        next = tmp
    }
}

fun main(args: Array<String>) {
    val limit = args.elementAtOrNull(1)?.toIntOrNull() ?: 100_000
    println(fibonacci.take(limit).last())
}

