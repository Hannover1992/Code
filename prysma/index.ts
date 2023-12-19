// noinspection JSDeprecatedSymbols

import { PrismaClient } from '@prisma/client'

const prisma = new PrismaClient()

// @ts-ignore
const main = async () => {
    // @ts-ignore
    const allUsers = await prisma.product.findMany()
    console.log(allUsers)
};

main()

// // @ts-ignore
// let promise = main()
//     .then(async () => await prisma.$disconnect())
//     // @ts-ignore
//     .catch(async e => {
//         console.error(e)
//         await prisma.$disconnect()
//     // @ts-ignore
//         process.exit(1)
//     });
